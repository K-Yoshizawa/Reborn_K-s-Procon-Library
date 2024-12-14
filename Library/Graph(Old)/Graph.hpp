#pragma once

/**
 * @file Graph.hpp
 * @brief Graph - グラフテンプレート
 * @version 1.0
 * @date 2024-09-01
 */

#include "../Common.hpp"

using Vertex = int;

template<typename CostType>
struct Edge{
    Edge() = default;
    Edge(int from, int to, CostType cost, int id = -1) : from(from), to(to), cost(cost), id(id){}
	
    int from{-1}, to{-1}, id{-1};
    CostType cost{1};
};

template<typename CostType = int32_t>
class Graph{
    public:
    Graph() = default;

    /**
     * @brief 頂点数 `vertex_size` のグラフを構築する。
     * @param vertex_size 頂点数
     * @param directed `true` の場合、有向グラフとして構築する `(default = false)`
     */
    Graph(int vertex_size, bool directed = false) : 
        vertex_(vertex_size), adjacent_list_(vertex_size),
        directed_flag_(directed){}

    /**
     * @brief グラフ G の頂点数を取得する。
     * @return size_t グラフ G の頂点数
     */
    size_t get_vertex_size() const {
        return vertex_;
    }

    /**
     * @brief グラフ G の辺数を取得する。
     * @return size_t グラフ G の辺数
     */
    size_t get_edge_size() const {
        return edge_;
    }

    /**
     * @brief グラフ G に対する十分大きな値(`INF`)を取得する。
     * @note `numeric_limits<CostType>::max() / 4` を採用している。
     * @return CostType `INF`
     */
    CostType get_inf() const {
        return inf_;
    }

    /**
     * @brief 2頂点 `s` `t` 間に重み `c` の辺を張る。有向グラフの場合は `s` から `t` への有向辺が、無向グラフの場合は `s` `t` 間の無向辺が張られる。
     * @param s 始点の頂点(有向辺)
     * @param t 終点の頂点(有向辺)
     * @param c 重み `(default = 1)`
     * @param id 辺の番号を明示的に指定する `(default = -1)`
     */
    void AddEdge(Vertex s, Vertex t, CostType c = 1, int id = -1){
        Validate(s);
        Validate(t);
        int edge_id = edge_++;
        if(id != -1) edge_id = id;
        adjacent_list_[s].push_back(Edge(s, t, c, edge_id));
        if(!directed_flag_){
            adjacent_list_[t].push_back(Edge(t, s, c, edge_id));
        }
    }

    /**
     * @brief グラフに指定した辺数の情報を入力する。
     * @note 入力形式が `u v w` または `u v` の形式で表される入力形式に対応している。
     * @param edge_count 辺数 E
     * @param weighted_graph 重み付き辺であるか `(default = true)`
     * @param one_index 頂点が1-indexであるか `(default = true)`
     */
    void InputGraph(int edge_count, bool weighted_graph = true, bool one_index = true){
        for(int i = 0; i < edge_count; ++i){
            int s, t; cin >> s >> t;
            if(one_index) --s, --t;
            CostType w = 1;
            if(weighted_graph) cin >> w;
            AddEdge(s, t, w);
        }
    }

    vector<Edge<CostType>> &operator[](Vertex v){
        return adjacent_list_[v];
    }

    const vector<Edge<CostType>> &operator[](Vertex v) const {
        return adjacent_list_[v];
    }

    inline void Validate(int vertex) const {
        assert(0 <= vertex && vertex < vertex_);
    }

    private:
    size_t vertex_{0}, edge_{0};
    vector<vector<Edge<CostType>>> adjacent_list_;

    bool directed_flag_;
    CostType inf_{numeric_limits<CostType>::max() / 4};
};

/**
 * @brief グラフの隣接行列を返す。
 * @note verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A
 * @note 計算量 : O(V + E)
 * @note 多重辺については、最も重みが小さい辺を採用
 * @param graph 頂点数 V のグラフ
 * @param not_adjacent_value 2頂点 u, v 間に辺が存在しない場合の値 `(default = 0)`
 * @attention 自己ループが含まれるグラフについては未定義
 * @return vector<vector<CostType>> V × V の隣接行列
 */
template<typename CostType>
vector<vector<CostType>> GraphConvertMatrix(const Graph<CostType> &graph, CostType not_adjacent_value = 0){
    size_t V = graph.get_vertex_size();
    vector<vector<CostType>> ret(V, vector<CostType>(V, not_adjacent_value));
    for(int i = 0; i < V; ++i){
        for(const Edge<CostType> &e : graph[i]){
            if(ret[i][e.to] == not_adjacent_value || ret[i][e.to] > e.cost){
                ret[i][e.to] = e.cost;
            }
        }
    }
    return ret;
}

/**
 * @brief グラフの辺を逆順にしたグラフを返す。
 * @param graph 頂点数 V のグラフ
 * @attention 無向グラフに対する動作は未定義
 * @return Graph<CostType> G の辺を逆にしたグラフ
 */
template<typename CostType>
Graph<CostType> GraphReverse(const Graph<CostType> &graph){
    size_t V = graph.get_vertex_size();
    Graph<CostType> ret(V, true);
    for(int i = 0; i < V; ++i){
        for(const Edge<CostType> &e : graph[i]){
            ret.AddEdge(e.to, e.from, e.cost);
        }
    }
    return ret;
}

/**
 * @brief グラフの辺集合を返す。
 * @param graph 頂点数 V のグラフ
 * @param sorted 辺集合をコストでソートした状態で返すか `(default = false)`
 * @return vector<Edge<CostType>> G の辺集合
 */
template<typename CostType>
vector<Edge<CostType>> GraphConvertEdgeSet(const Graph<CostType> &graph, bool sorted = false){
    vector<Edge<CostType>> ret;
    set<int> picked;
    for(int v = 0; v < graph.get_vertex_size(); ++v){
        for(Edge<CostType> e : graph[v]){
            if(!picked.contains(e.id)){
				ret.emplace_back(e);
                picked.insert(e.id);
			}
        }
    }
    if(sorted){
        sort(ret.begin(), ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){
            return l.cost < r.cost;
        });
    }
    return ret;
}