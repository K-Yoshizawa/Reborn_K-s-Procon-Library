/**
 * @file Dijkstra.hpp
 * @brief Dijkstra - ダイクストラ法
 * @date 2024-12-12
 */

#include "../Common.hpp"

using Vertex = int;

template<typename WeightType, bool isDirected = false>
class Dijkstra{
    private:
    vector<vector<pair<Vertex, WeightType>>> graph;
    vector<WeightType> dist;
    vector<Vertex> prev_vertex;
    WeightType INF = get_INF<WeightType>();

    public:
    Dijkstra(int vertex_size) : graph(vertex_size), dist(vertex_size), prev_vertex(vertex_size){}
    
    void AddEdge(Vertex s, Vertex t, WeightType w){
        graph.at(s).emplace_back(t, w);
        if(!isDirected){
            graph.at(t).emplace_back(s, w);
        }
    }

    void Solve(Vertex source){
        fill(dist.begin(), dist.end(), INF);
        fill(prev_vertex.begin(), prev_vertex.end(), -1);
        dist.at(source) = WeightType();
        using P = pair<WeightType, Vertex>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(WeightType(), source);
        while(!que.empty()){
            auto [d, u] = que.top(); que.pop();
            if(dist.at(u) != d) continue;
            for(auto [v, w] : graph.at(u)){
                if(dist.at(v) > d + w){
                    dist.at(v) = d + w;
                    prev_vertex.at(v) = u;
                    que.emplace(d + w, v);
                }
            }
        }
    }

    WeightType Distance(Vertex target) const {
        return dist.at(target);
    }

    bool Reachable(Vertex target) const {
        return dist.at(target) != INF;
    }

    vector<tuple<Vertex, Vertex, WeightType>> Restore(Vertex target){
        vector<tuple<Vertex, Vertex, WeightType>> res;
        if(!Reachable(target)) return res;
        Vertex v = target;
        while(prev_vertex.at(v) != -1){
            int u = prev_vertex.at(v);
            WeightType w = dist.at(v) - dist.at(u);
            res.emplace_back(u, v, w);
            v = u;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};