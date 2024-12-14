/**
 * @file FunctionalGraph.hpp
 * @brief Functional Graph
 * @version 2.0
 * @date 2024-10-27
 */

#include "../Common.hpp"

template<typename CostType = int32_t>
class FunctionalGraph{
    public:
    /**
     * @brief 重みなし Functional Graph の構築を行う。
     * @param to 各頂点 i が接続している頂点
     * @param one_index 頂点番号を 1-index として扱うか `(default = true)`
     * @param doubling_size ダブリングのテーブルサイズ `(default = 60)`
     */
    FunctionalGraph(vector<int> &to, bool one_index = true, int doubling_size = 60) :
        vertex_size_((int)to.size()), doubling_size_(doubling_size), one_index_(one_index){
        vector<CostType> cost(vertex_size_, 1);
        Build(to, cost);
    }
    
    /**
     * @brief 重みあり Functional Graph の構築を行う。
     * @param to 各頂点 i が接続している頂点
     * @param cost 各頂点 i が接続している頂点への辺の重み
     * @param one_index 頂点番号を 1-index として扱うか `(default = true)`
     * @param doubling_size ダブリングのテーブルサイズ `(default = 60)`
     */
    FunctionalGraph(vector<int> &to, vector<CostType> &cost, bool one_index = true, int doubling_size = 60) :
        vertex_size_((int)to.size()), doubling_size_(doubling_size), one_index_(one_index){
        Build(to, cost);
    }

    /**
     * @brief 各サイクルを構成する頂点の一覧を返す。
     * @note verify : https://atcoder.jp/contests/abc311/submissions/59194783
     * @return vector<vector<int>> 各サイクルを構成する頂点の一覧
     */
    vector<vector<int>> &get_cycle(){
        return cycle_;
    }

    /**
     * @brief 頂点 `start` から `step` 回移動する先の頂点を求める。
     * @note verify : https://atcoder.jp/contests/abc167/submissions/59194517
     * @param start 開始頂点
     * @param step 移動回数
     * @return int 移動先の頂点
     */
    int Jump(int start, int64_t step){
        int ret = start - one_index_;
        int64_t k = step, d = 0;
        while(k){
            if(k & 1) ret = next_to_[d][ret];
            k >>= 1, ++d;
        }
        return ret + one_index_;
    }

    /**
     * @brief 頂点 `start` から `step` 回移動するときの辺の重みの総和を求める。
     * @note verify : https://atcoder.jp/contests/abc179/submissions/59194689
     * @param start 開始頂点
     * @param step 移動回数
     * @return CostType 辺の重みの総和
     */
    CostType JumpCost(int start, int64_t step){
        CostType ret = 0;
        int64_t k = step, d = 0;
        int v = start - one_index_;
        while(k){
            if(k & 1){
                ret += next_cost_[d][v];
                v = next_to_[d][v];
            }
            k >>= 1, ++d;
        }
        return ret;
    }

    /**
     * @brief 頂点 `v` が属するサイクルのサイズを取得する。
     * @note verify : https://atcoder.jp/contests/abc377/submissions/59194861
     * @param v 頂点番号
     * @return int 頂点が属するサイクルのサイズ、ただしサイクルに属していない場合は 0 を返す
     */
    int CycleSize(int v){
        int i = v - one_index_;
        if(belong_cycle_[i] == -1) return 0;
        return (int)cycle_[belong_cycle_[i]].size();
    }

    private:
    int vertex_size_, doubling_size_, one_index_;

    vector<vector<int>> next_to_;
    vector<vector<CostType>> next_cost_;

    vector<int> belong_cycle_;
    vector<vector<int>> cycle_;

    void Build(vector<int> &to, vector<CostType> &cost){
        next_to_.resize(doubling_size_, vector<int>(vertex_size_, -1));
        next_cost_.resize(doubling_size_, vector<CostType>(vertex_size_, 0));
        for(int i = 0; i < vertex_size_; ++i){
            next_to_[0][i] = to[i] - (int)one_index_;
            next_cost_[0][i] = cost[i];
        }
        for(int i = 1; i < doubling_size_; ++i){
            for(int j = 0; j < vertex_size_; ++j){
                next_to_[i][j] = next_to_[i - 1][next_to_[i - 1][j]];
                next_cost_[i][j] = next_cost_[i - 1][next_to_[i - 1][j]] + next_cost_[i - 1][j];
            }
        }

        belong_cycle_.resize(vertex_size_, -1);
        vector<int> state(vertex_size_, 0);
        vector<int> history;
        auto dfs = [&](auto self, int v) -> void {
            if(state[v] == 2) return;
            history.push_back(v);
            state[v] = 1;
            int u = next_to_[0][v];
            if(state[u] == 1){
                int cycle_idx = cycle_.size();
                cycle_.push_back({});
                for(int i = history.size() - 1;; --i){
                    cycle_.back().push_back(history[i] + one_index_);
                    belong_cycle_[history[i]] = cycle_idx;
                    if(history[i] == u) break;
                }
                reverse(cycle_.back().begin(), cycle_.back().end());
            }
            else{
                self(self, u);
            }
            history.pop_back();
            state[v] = 2;
        };
        for(int i = 0; i < vertex_size_; ++i) dfs(dfs, i);
    }
};