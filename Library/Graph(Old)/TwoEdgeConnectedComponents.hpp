/**
 * @file TwoEdgeConnectedComponents.hpp
 * @brief Two-Edge-Connected Components - 二辺連結成分分解
 * @version 1.0
 * @date 2024-10-21
 */

#include "LowLink.hpp"
#include "../Tree/Tree.hpp"

template<typename CostType>
class TwoEdgeConnectedComponents{
    public:
    /**
     * @brief グラフから二辺連結成分分解を行う。
     */
    TwoEdgeConnectedComponents(Graph<CostType> &graph) : G(graph){
        LowLink<CostType> lowlink(G);
        belong_components_.resize(G.get_vertex_size(), -1);
        vector<Edge<CostType>> bridges = lowlink.get_bridge();
        vector<bool> is_bridge(G.get_edge_size(), false);
        for(Edge<CostType> &es : bridges){
            is_bridge[es.id] = true;
        }
        vector<bool> visited(G.get_vertex_size(), false);
        queue<Vertex> que;
        for(int s = 0; s < G.get_vertex_size(); ++s){
            if(visited[s]) continue;
            que.push(s);
            visited[s] = true;
            int component_index = components_.size();
            components_.push_back({});
            while(que.size()){
                Vertex v = que.front();
                components_.back().push_back(v);
                belong_components_[v] = component_index;
                que.pop();
                for(Edge<CostType> &es : G[v]){
                    if(is_bridge[es.id]) continue;
                    if(visited[es.to]) continue;
                    que.push(es.to);
                    visited[es.to] = true;
                }
            }
        }
        adjacent_list_of_bridge_tree_.resize(components_.size());
        for(int i = 0; i < bridges.size(); ++i){
            if(is_bridge[bridges[i].id]){
                Vertex u = get_belong_component(bridges[i].from);
                Vertex v = get_belong_component(bridges[i].to);
                adjacent_list_of_bridge_tree_[u].emplace_back(v, bridges[i].cost);
                adjacent_list_of_bridge_tree_[v].emplace_back(u, bridges[i].cost);
            }
        }
    }

    /**
     * @brief すべての二辺連結成分とそれに含まれるすべての頂点を列挙する。
     */
    vector<vector<Vertex>> &get_components(){
        return components_;
    }

    /**
     * @brief 頂点 `v` が所属する二辺連結成分のインデックスを返す。
     */
    int get_belong_component(Vertex v) const {
        return belong_components_[v];
    }

    /**
     * @brief 二辺連結成分を縮約した根付き木を生成する。
     * @note verify : https://atcoder.jp/contests/arc039/tasks/arc039_d
     * @return RootedTree<CostType> 二辺連結成分を縮約した根付き木
     */
    RootedTree<CostType> ConstructBridgeTree() const {
        int V = (int)components_.size();
        RootedTree<CostType> ret(V);
        auto dfs = [&](auto self, Vertex v, Vertex p) -> void {
            for(auto [u, c] : adjacent_list_of_bridge_tree_[v]){
                if(u == p) continue;
                ret.AddEdge(v, u, c);
                self(self, u, v);
            }
        };
        dfs(dfs, 0, -1);
        return ret;
    }
    
    private:
    Graph<CostType> &G;

    vector<vector<Vertex>> components_;
    vector<int> belong_components_;
    vector<vector<pair<int, CostType>>> adjacent_list_of_bridge_tree_;
};