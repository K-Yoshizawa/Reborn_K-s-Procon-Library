/**
 * @file EulerianTrail.hpp
 * @brief Eulerian Trail - オイラー路
 * @version 0.1
 * @date 2024-03-08
 */

#include "GraphTemplate.hpp"

template<typename CostType>
struct EulerianTrail{
    private:
    Graph<CostType> &G;
    int m_esize;
    vector<bool> m_used;
    vector<int> m_index;
    bool m_exist{true};
    vector<Vertex> m_trail_vertex;
    vector<int> m_trail_edge;

    void m_dfs(Vertex v, int pe){
        while(m_index[v] < G[v].size()){
            auto e = G[v][m_index[v]++];
            if(m_used[e.id]) continue;
            m_used[e.id] = true;
            m_dfs(e.to, e.id);
        }
        m_trail_vertex.push_back(v);
        if(pe != -1) m_trail_edge.push_back(pe);
    }

    public:
    EulerianTrail(Graph<CostType> &G, int EdgeSize) : G(G), m_esize(EdgeSize){
        m_used.resize(EdgeSize, 0);
        m_index.resize(G.size(), 0);
        int start = 0;
        if(G.is_directed()){
            int cnts = 0, cntt = 0;
            for(int i = 0; i < G.size(); ++i){
                if(G[start].size() == 0) start = i;
                if(G.indegree(i) == G.outdegree(i)) continue;
                if(G.indegree(i) + 1 == G.outdegree(i)){
                    ++cnts, start = i;
                    continue;
                }
                if(G.indegree(i) == G.outdegree(i) + 1){
                    ++cntt;
                    continue;
                }
                m_exist = false;
            }
            m_exist &= (cnts <= 1 and cnts == cntt);
        }
        else{
            int odd = 0;
            for(int i = 0; i < G.size(); ++i){
                if(G[start].size() == 0) start = i;
                if(G[i].size() % 2) ++odd, start = i;
            }
            m_exist &= (odd == 0 or odd == 2);
        }
        if(m_exist){
            m_dfs(start, -1);
            reverse(m_trail_vertex.begin(), m_trail_vertex.end());
            reverse(m_trail_edge.begin(), m_trail_edge.end());
            m_exist &= m_trail_edge.size() == EdgeSize;
        }
    }

    bool exist(){
        return m_exist;
    }

    vector<Vertex> &trail_vertex(){
        assert(m_exist);
        return m_trail_vertex;
    }

    vector<int> &trail_edge(){
        assert(m_exist);
        return m_trail_edge;
    }
};