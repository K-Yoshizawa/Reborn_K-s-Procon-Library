/**
 * @file Dijkstra.hpp
 * @brief Dijkstra - ダイクストラ法
 * @version 4.0
 * @date 2024-09-01
 */

#include "Graph.hpp"

template<typename CostType>
class Dijkstra{
    public:
    Dijkstra(Graph<CostType> &G) : 
            graph_(G), inf_(G.get_inf()), dist_(G.get_vertex_size(), inf_),
            prev_vertex_(G.get_vertex_size(), -1){}

    /**
     * @brief 頂点 `source` から他の全頂点への最短距離を求める。
     * @note 到達不能の場合、`inf` となる。
     * @param source 始点の頂点
     */
    void Solve(Vertex source){
        graph_.Validate(source);
        if(source_vertex_ == source) return;
        dist_.assign(dist_.size(), inf_);
        prev_vertex_.assign(prev_vertex_.size(), -1);
        dist_[source] = 0;
        using P = pair<CostType, Vertex>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, source);
        while(que.size()){
            auto [d, v] = que.top(); que.pop();
            if(dist_[v] != d) continue;
            for(Edge<CostType> &e : graph_[v]){
                CostType nd = d + e.cost;
                if(nd < dist_[e.to]){
                    dist_[e.to] = nd;
                    prev_vertex_[e.to] = v;
                    que.emplace(nd, e.to);
                }
            }
        }
        source_vertex_ = source;
    }

    /**
     * @brief 頂点 `source` から頂点 `target` に到達可能かを返す。
     * @attention 予め始点の頂点 `source` について `Solve()` を呼び出している必要がある。
     * @param target 終点の頂点
     * @return true 到達可能
     * @return false 到達不能
     */
    bool Reachable(Vertex target) const {
        graph_.Validate(target);
        return dist_[target] != inf_;
    }

    /**
     * @brief 頂点 `source` から頂点 `target` への最短パスを返す。
     * @attention 予め始点の頂点 `source` について `Solve()` を呼び出している必要がある。
     * @attention 頂点 `target` に到達不能の場合、空列を返す。
     * @param target 終点の頂点
     * @return vector<Vertex> 最短パスに含まれる頂点列を `source` から `target` の順に並べたもの。到達不能の場合は空列が返される。
     */
    vector<Vertex> Restore(Vertex target) const {
        graph_.Validate(target);
        if(!Reachable(target)) return vector<Vertex>{};
        vector<Vertex> ret{target};
        Vertex v = target;
        while(v != source_vertex_){
            v = prev_vertex_[v];
            ret.push_back(v);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    /**
     * @brief 頂点 `source` から頂点 `target` への最短経路長を返す。
     * @attention 予め始点の頂点 `source` について `Solve()` を呼び出している必要がある。
     * @attention 到達不能の場合は `inf` が返される。
     * @param target 終点の頂点
     * @return CostType 最短経路長
     */
    CostType Distance(Vertex target) const {
        graph_.Validate(target);
        return dist_[target];
    }

    CostType operator[](Vertex target){
        return Distance(target);
    }

    const CostType operator[](Vertex target) const {
        return Distance(target);
    }

    private:
    Graph<CostType> &graph_;

    CostType inf_;
    vector<CostType> dist_;
    vector<Vertex> prev_vertex_;
    Vertex source_vertex_{-1};
};