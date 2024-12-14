/**
 * @file StronglyConnectedComponents.hpp
 * @brief Strongly Connected Components - 強連結成分分解
 * @version 4.0
 * @date 2024-07-19
 */

#include "Graph.hpp"

template<typename CostType>
struct StronglyConnectedComponents{
    public:
    /**
     * @brief 有向グラフ G を強連結成分分解する。
     */
    StronglyConnectedComponents(Graph<CostType> &G) : graph_(G), V(G.get_vertex_size()){
        rev_graph_ = GraphReverse(G);
        vector<int> label(V, -1);
        vector<bool> state(V, false);
        int nex = 0;
        vector<Vertex> vs(V);
        iota(vs.begin(), vs.end(), 0);
        for(auto v : vs){
            if(!state[v]) dfs1(v, label, nex, state);
        }
        sort(vs.begin(), vs.end(), [&](Vertex u, Vertex v){
            return label[u] > label[v];
        });
        belong_.resize(V, -1);
        for(auto v : vs){
            if(state[v]){
                int c = components_.size();
                components_.push_back(vector<Vertex>{});
                dfs2(v, label, c, state);
            }
        }
    }

    /**
     * @brief 強連結成分を取得する。
     * @note 強連結成分はトポロジカル順に並んでいる。
     * @note verify : https://judge.yosupo.jp/problem/scc
     * @return vector<vector<Vertex>>& 強連結成分の一覧
     */
    vector<vector<Vertex>> &get_components(){
        return components_;
    }

    /**
     * @brief 強連結成分の数を取得する。
     * @return size_t 強連結成分の数
     */
    size_t get_components_size(){
        return components_.size();
    }

    /**
     * @brief グラフ G の頂点 `v` がどの強連結成分に属するかを返す。
     * @param v グラフ G の頂点
     * @return int 所属する強連結成分の番号
     */
    int BelongComponent(Vertex v){
        return belong_[v];
    }

    /**
     * @brief グラフの頂点をトポロジカルソートした結果を返す。
     * @return vector<Vertex> トポロジカルソート順に並んだ頂点番号列
     */
    vector<Vertex> TopologicalSort(){
        vector<Vertex> ret;
        for(auto &vs : components_){
            for(auto &v : vs){
                ret.emplace_back(v);
            }
        }
        return ret;
    }

    private:
    Graph<CostType> &graph_;
    Graph<CostType> rev_graph_;

    size_t V;
    vector<vector<Vertex>> components_;
    vector<int> belong_;

    void dfs1(Vertex v, vector<int> &label, int &nex, vector<bool> &state){
        state[v] = true;
        for(auto &e : graph_[v]){
            if(state[e.to]) continue;
            dfs1(e.to, label, nex, state);
        }
        label[v] = nex++;
        return;
    }

    void dfs2(Vertex v, vector<int> &label, int component, vector<bool> &state){
        components_[component].push_back(v);
        belong_[v] = component;
        state[v] = false;
        for(auto &e : rev_graph_[v]){
            if(!state[e.to]) continue;
            dfs2(e.to, label, component, state);
        }
        return;
    }
};