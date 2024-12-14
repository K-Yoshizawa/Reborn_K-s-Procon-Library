/**
 * @file Kruskal.hpp
 * @brief Kruskal - 最小全域木
 * @version 4.0
 * @date 2024-10-21
 */

#include "Graph.hpp"
#include "../DataStructure/UnionFind.hpp"

template<typename CostType, bool MaximumSpanningTree = false>
struct Kruskal{
    private:
    Graph<CostType> &G;
    vector<int> remain_edge_id_;
    CostType cost_;

    public:
    /**
     * @brief グラフを基に全域木を構築する。
     * @param graph 頂点数 V のグラフ
     */
    Kruskal(Graph<CostType> &graph) : G(graph){
        cost_ = 0;
        UnionFind uf(G.get_vertex_size());
        auto es = GraphConvertEdgeSet(G, true);
        if(MaximumSpanningTree) reverse(es.begin(), es.end());
        for(Edge<CostType> &e : es){
            int i = e.id;
            if(uf.Same(e.from, e.to)) continue;
            uf.Unite(e.from, e.to);
            remain_edge_id_.push_back(i);
            cost_ += e.cost;
        }
    }

    /**
     * @brief 全域木に含まれる辺番号を返す。
     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree
     * @return vector<int>& 辺番号のベクトル
     */
    vector<int> &get_edge_id(){
        return remain_edge_id_;
    }

    /**
     * @brief 全域木のコストを返す。
     * @note verify : https://judge.yosupo.jp/problem/minimum_spanning_tree
     * @return CostType 全域木のコスト
     */
    CostType get_cost() const {
        return cost_;
    }
};