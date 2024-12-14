/**
 * @file WarshallFloyd.hpp
 * @author log_K (lX57)
 * @brief WarshallFloyd - 全点対間最短経路
 * @version 4.0
 * @date 2024-09-01
 */

#include "Graph.hpp"

template<typename CostType>
class WarshallFloyd{
    public:
    /**
     * @brief グラフ G における全点間最短経路問題を解く。
     * @note 計算量 : O(V ^ 3)
     * @param G 頂点数 V のグラフ
     */
    WarshallFloyd(Graph<CostType> &G) :
            vertex_size_(G.get_vertex_size()), inf_(G.get_inf()),
            dist_(GraphConvertMatrix(G, inf_)){
        Solve();
    }

    /**
     * @brief 隣接行列 M で表されるグラフ G における全点間最短経路問題を解く。
     * @note 計算量 : O(V ^ 3)
     * @param matrix 頂点数 V のグラフ G の隣接行列
     */
    WarshallFloyd(vector<vector<CostType>> &matrix) :
            vertex_size_((int)matrix.size()), inf_(numeric_limits<CostType>::max() / 4),
            dist_(matrix){
        Solve();
    }

    /**
     * @brief 頂点 `source` から頂点 `target` に到達可能かを返す。
     * @param source 始点の頂点 (0-index)
     * @param target 終点の頂点
     * @return true 到達可能
     * @return false 到達不能
     */
    bool Reachable(Vertex source, Vertex target) const {
        Validate(source);
        Validate(target);
        return dist_[source][target] != inf_;
    }

    /**
     * @brief グラフが負閉路を持つかを返す。
     */
    inline bool Negative() const {
        return negative_cycle_;
    }

    /**
     * @brief 頂点 `source` から頂点 `target` までの最短経路長を返す。
     * @param source 始点の頂点 (0-index)
     * @param target 終点の頂点 (0-index)
     * @return CostType 頂点 `source` から頂点 `target` までの最短経路長
     */
    CostType Distance(Vertex source, Vertex target) const {
        Validate(source);
        Validate(target);
        return dist_[source][target];
    }

    /**
     * @brief 全点間最短経路長を行列形式で出力する。負閉路を含むならその旨を出力する。
     * @note verify : https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
     * @param negative_cycle_message 負閉路を持つとき、代わりに出力するメッセージ `(deafult = "NEGATIVE CYCLE")`
     */
    void Print(string negative_cycle_message = "NEGATIVE CYCLE") const {
        if(Negative()){
            cout << negative_cycle_message << endl;
            return;
        }
        for(int i = 0; i < vertex_size_; ++i){
            for(int j = 0; j < vertex_size_; ++j){
                if(!Reachable(i, j)) cout << "INF";
                else cout << Distance(i, j);
                cout << " \n"[j + 1 == vertex_size_];
            }
        }
    }

    private:
    void Solve(){
        for(int i = 0; i < vertex_size_; ++i){
            dist_[i][i] = 0;
        }
        for(int k = 0; k < vertex_size_; ++k){
            for(int i = 0; i < vertex_size_; ++i){
                for(int j = 0; j < vertex_size_; ++j){
                    if(dist_[i][k] == inf_ || dist_[k][j] == inf_) continue;
                    dist_[i][j] = min(dist_[i][j], dist_[i][k] + dist_[k][j]);
                }
            }
        }
        for(int i = 0; i < vertex_size_; ++i){
            negative_cycle_ |= dist_[i][i] < 0;
        }
    }

    bool negative_cycle_{false};
    int vertex_size_;
    CostType inf_;
    vector<vector<CostType>> dist_{};

    inline void Validate(int vertex) const {
        if(!(0 <= vertex && vertex < vertex_size_)){
            cerr << "# [Warshall-Floyd] Failed Validate : Vertex " << vertex << endl;
            assert(false);
        }
    }
};