/**
 * @file BellmanFord.hpp
 * @brief BellmanFord - ベルマンフォード法
 * @version 4.0
 * @date 2024-09-01
 */

#include "Graph.hpp"

template<typename CostType>
class BellmanFord{
    public:
    /**
     * @brief グラフ graph における負辺有り単一始点最短路問題を解く。
     * @note 計算量 : O(EV)
     * @param graph 頂点数 V, 辺数 E のグラフ
     * @param source 始点の頂点 (0-index)
     */
    BellmanFord(const Graph<CostType> &graph, Vertex source) :
            vertex_size_(graph.get_vertex_size()), edge_set_(GraphConvertEdgeSet(graph, false)),
            source_vertex_(source), inf_(graph.get_inf()), dist_(vertex_size_, inf_){
        Validate(source_vertex_);
        dist_[source_vertex_] = 0;
        int update_count = 0;
        while(1){
            if(update_count == vertex_size_){
                negative_cycle_ = true;
                break;
            }
            bool update_flag = false;
            for(Edge<CostType> &e : edge_set_){
                if(dist_[e.from] == inf_) continue;
                if(dist_[e.to] > dist_[e.from] + e.cost){
                    dist_[e.to] = dist_[e.from] + e.cost;
                    update_flag = true;
                }
            }
            if(!update_flag) break;
            ++update_count;
        }
    }
    
    /**
     * @brief 頂点 `source` から頂点 `target` に到達可能かを返す。
     * @param target 終点の頂点
     * @return true 到達可能
     * @return false 到達不能
     */
    bool Reachable(Vertex target) const {
        Validate(target);
        return dist_[target] != inf_;
    }

    /**
     * @brief グラフが負閉路を持つかを返す。
     */
    inline bool Negative() const {
        return negative_cycle_;
    }

    /**
     * @brief 頂点 `source` から頂点 `target` までの最短経路長を返す。
     * @param target 終点の頂点 (0-index)
     * @attention 負閉路を持つときに返す値は未定義である。
     * @return CostType 頂点 `source` から頂点 `target` までの最短経路長
     */
    CostType Distance(Vertex target) const {
        Validate(target);
        return dist_[target];
    }

    CostType operator[](Vertex target){
        return Distance(target);
    }

    const CostType operator[](Vertex target) const {
        return Distance(target);
    }

    private:
    int vertex_size_;
    vector<Edge<CostType>> edge_set_;
    Vertex source_vertex_{-1};
    CostType inf_;
    vector<CostType> dist_;
    bool negative_cycle_{false};

    inline void Validate(int vertex) const {
        if(!(0 <= vertex && vertex < vertex_size_)){
            cerr << "# [Bellman-Ford] Failed Validate : Vertex " << vertex << endl;
            assert(false);
        }
    }
};