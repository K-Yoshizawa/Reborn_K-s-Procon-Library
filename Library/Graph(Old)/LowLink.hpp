#pragma once

/**
 * @file LowLink.hpp
 * @brief LowLink - 橋と関節点
 * @version 1.0
 * @date 2024-09-02
 */

#include "Graph.hpp"

template<typename CostType>
class LowLink{
    public:
    LowLink(Graph<CostType> &graph) :
            graph_(graph), ord_(graph.get_vertex_size()), low_(graph.get_vertex_size()),
            child_(graph.get_vertex_size()), state_(graph.get_vertex_size(), 0){
        for(int i = 0; i < graph.get_vertex_size(); ++i){
            if(!state_[i]) dfs(i, -1, 0);
        }
        BuildArticulationVertex();
        BuildBridge();
    }

    /**
     * @brief 頂点 `v` の `ord[v]` を返す。
     * @param v 頂点番号 (0-index)
     * @return int 
     */
    int get_ord(Vertex v) const {
        graph_.Validate(v);
        return ord_[v];
    }

    /**
     * @brief 頂点 `v` の `low[v]` を返す。
     * @param v 頂点番号 (0-index)
     * @return int 
     */
    int get_low(Vertex v) const {
        graph_.Validate(v);
        return low_[v];
    }

    /**
     * @brief 関節点を列挙する。
     * @note 関節点 : その頂点を除くと連結成分が増えるような頂点
     * @return vector<Vertex> 関節点の頂点番号 (0-index)
     */
    vector<Vertex> &get_articulation_vertex(){
        return articulation_vertex_;
    }

    /**
     * @brief 橋を列挙する。
     * @note 橋 : その辺を除くと連結成分が増えるような頂点
     * @return vector<Edge<CostType>> 橋である辺
     */
    vector<Edge<CostType>> &get_bridge(){
        return bridge_;
    }

    private:
    bool dfs(Vertex v, int p, int order){
        if(state_[v] != 0) return false;
        // cerr << "# (v, p, order) = (" << v << ", " << p << ", " << order << ")" << endl;
        state_[v] = 1 + (p == -1);
        ord_[v] = low_[v] = order;
        for(Edge<CostType> &e : graph_[v]){
            if(e.id == p) continue;
            child_[v].push_back(e.to);
            if(dfs(e.to, e.id, order + 1)){
                low_[v] = min(low_[v], low_[e.to]);
            }
            else{
                child_[v].pop_back();
                low_[v] = min(low_[v], ord_[e.to]);
            }
        }
        return true;
    }

    void BuildArticulationVertex(){
        for(int u = 0; u < graph_.get_vertex_size(); ++u){
            if(state_[u] == 2){
                if(child_[u].size() > 1) articulation_vertex_.push_back(u);
                continue;
            }
            bool exist = false;
            for(Vertex v : child_[u]){
                exist |= (get_ord(u) <= get_low(v));
            }
            if(exist) articulation_vertex_.push_back(u);
        }
    }

    void BuildBridge(){
        auto es = GraphConvertEdgeSet(graph_, false);
        for(Edge<CostType> e : es){
            Vertex u = e.from, v = e.to;
            if(get_ord(u) >= get_ord(v)) swap(u, v);
            if(get_ord(u) < get_low(v)) bridge_.push_back(e);
        }
    }

    Graph<CostType> &graph_;
    vector<int> ord_, low_, state_;
    vector<vector<Vertex>> child_;

    vector<Vertex> articulation_vertex_;
    vector<Edge<CostType>> bridge_;
};