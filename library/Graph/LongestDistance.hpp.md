---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Longest Distance - DAG\u306B\u304A\u3051\u308B\u6700\u9577\u8DDD\
      \u96E2"
    links: []
  bundledCode: "#line 1 \"library/Graph/LongestDistance.hpp\"\n/**\n * @file LongestDistance.hpp\n\
    \ * @author log K (lX57)\n * @brief Longest Distance - DAG\u306B\u304A\u3051\u308B\
    \u6700\u9577\u8DDD\u96E2\n * @version 1.0\n * @date 2024-02-11\n */\n\n#line 2\
    \ \"library/Graph/GraphTemplate.hpp\"\n\n/**\n * @file GraphTemplate.hpp\n * @brief\
    \ Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 3.0\n * @date 2024-01-09\n */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n \
    \   public:\n    Vertex from, to;\n    CostType cost;\n    int loc{-1}, id{-1};\n\
    \n    Edge() = default;\n    Edge(Vertex from, Vertex to, CostType cost) : from(from),\
    \ to(to), cost(cost){}\n\n    operator int(){\n        return to;\n    }\n};\n\
    \ntemplate<typename CostType = int>\nstruct Graph{\n    private:\n    int m_vertex_size{0},\
    \ m_edge_size{0};\n    bool m_is_directed{false}, m_is_weighted{false};\n    vector<vector<Edge<CostType>>>\
    \ m_adj;\n    vector<int> m_indegree;\n\n    public:\n    CostType INF{numeric_limits<CostType>::max()\
    \ >> 2};\n\n    Graph() = default;\n\n    /**\n     * @brief `vertex_size` \u9802\
    \u70B9 `0` \u8FBA\u306E\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\u3002\n\
    \     * @note `directed` \u3092 `true` \u306B\u3059\u308B\u3068\u6709\u5411\u30B0\
    \u30E9\u30D5\u306B\u306A\u308B\u3002\n     * @param vertex_size \u9802\u70B9\u6570\
    \n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\
    \u308B\u304B (option, default = `false`)\n     */\n    Graph(int vertex_size,\
    \ bool directed = false) : m_vertex_size(vertex_size), m_is_directed(directed){\n\
    \        m_adj.resize(vertex_size);\n        m_indegree.resize(vertex_size, 0);\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `from` \u304B\u3089\u9802\u70B9\
    \ `to` \u306B\u8FBA\u3092\u5F35\u308B\u3002\n     * @note `cost` \u3092\u6307\u5B9A\
    \u3059\u308B\u3053\u3068\u3067\u91CD\u307F\u3092\u3064\u3051\u308B\u3053\u3068\
    \u304C\u3067\u304D\u308B\u3002\n     * @param from \u9802\u70B9\u756A\u53F7\n\
    \     * @param to \u9802\u70B9\u756A\u53F7\n     * @param cost \u91CD\u307F (option,\
    \ default = `1`)\n     */\n    void add(Vertex from, Vertex to, CostType cost\
    \ = 1){\n        assert(0 <= from and from < m_vertex_size);\n        assert(0\
    \ <= to and to < m_vertex_size);\n        m_is_weighted |= cost > 1;\n       \
    \ Edge<CostType> e1(from, to, cost);\n        e1.loc = m_adj[from].size();\n \
    \       e1.id = m_edge_size;\n        m_adj[from].push_back(e1);\n        ++m_edge_size;\n\
    \        if(m_is_directed){\n            ++m_indegree[to];\n            return;\n\
    \        }\n        Edge<CostType> e2(to, from, cost);\n        e2.loc = m_adj[to].size();\n\
    \        e2.id = e1.id;\n        m_adj[to].push_back(e2);\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u306B `edge_size` \u672C\u306E\u8FBA\u3092\u5165\
    \u529B\u3055\u305B\u308B\u3002\n     * @param edge_size \u5165\u529B\u3059\u308B\
    \u8FBA\u6570\n     * @param weighted \u91CD\u307F\u4ED8\u304D\u8FBA\u304B (option,\
    \ default = `false`)\n     * @param zero_index \u5165\u529B\u306E\u9802\u70B9\u756A\
    \u53F7\u304C 0-index \u304B (option, default = `false`)\n     */\n    void input(int\
    \ edge_size, bool weighted = false, bool zero_index = false){\n        m_is_weighted\
    \ = weighted;\n        for(int i = 0; i < edge_size; ++i){\n            Vertex\
    \ s, t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n            CostType\
    \ c = 1;\n            if(weighted) cin >> c;\n            add(s, t, c);\n    \
    \    }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\
    \u3092\u8FD4\u3059\u3002\n     * @return size_t \u9802\u70B9\u6570\n     */\n\
    \    size_t size(){\n        return m_vertex_size;\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9 `v` \u306E\u51FA\u6B21\u6570\u3092\u8FD4\u3059\u3002\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return int \u9802\u70B9 `v` \u306E\u51FA\
    \u6B21\u6570\n     */\n    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\u3092\
    \u8FD4\u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return int\
    \ \u9802\u70B9 `v` \u306E\u5165\u6B21\u6570\n     */\n    int indegree(Vertex\
    \ v){\n        if(m_is_directed) return m_indegree.at(v);\n        else return\
    \ (int)m_adj.at(v).size();\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\
    \u304C\u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\
    \u3002\n     */\n    bool is_directed(){\n        return m_is_directed;\n    }\n\
    \n    /**\n     * @brief \u30B0\u30E9\u30D5\u304C\u91CD\u307F\u4ED8\u304D\u304B\
    \u3069\u3046\u304B\u3092\u8FD4\u3059\u3002\n     */\n    bool is_weighted(){\n\
    \        return m_is_weighted;\n    }\n\n    vector<Vertex> source(){\n      \
    \  assert(m_is_directed);\n        vector<Vertex> ret;\n        for(int i = 0;\
    \ i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> sink(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(outdegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 1) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9\
    \ `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u3002\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>>& \u9802\u70B9\
    \ `v` \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\n     */\n    vector<Edge<CostType>>\
    \ &get_adj(Vertex v){\n        return m_adj.at(v);\n    }\n\n    /**\n     * @brief\
    \ \u8FBA\u306E\u5411\u304D\u3092\u3059\u3079\u3066\u9006\u306B\u3057\u305F\u30B0\
    \u30E9\u30D5\u3092\u8FD4\u3059\u3002\n     * @attention \u6709\u5411\u30B0\u30E9\
    \u30D5\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u4EF6\u3068\u3059\u308B\u3002\
    \n     * @return Graph<CostType> \u9006\u8FBA\u30B0\u30E9\u30D5\n     */\n   \
    \ Graph<CostType> reverse(){\n        assert(m_is_directed);\n        Graph ret(m_vertex_size,\
    \ true);\n        for(auto es : m_adj){\n            for(auto e : es){\n     \
    \           ret.add(e.to, e.from, e.cost);\n            }\n        }\n       \
    \ return ret;\n    }\n\n    /**\n     * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\u3092\u8FD4\u3059\u3002\n   \
    \  * @attention \u6709\u5411\u30B0\u30E9\u30D5\u3067\u3042\u308B\u3053\u3068\u3092\
    \u8981\u4EF6\u3068\u3059\u308B\u3002\n     * @return vector<Vertex> \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3057\u305F\u9802\u70B9\u5217\n   \
    \  */\n    vector<Vertex> topological_sort(){\n        assert(m_is_directed);\n\
    \        vector<Vertex> ret;\n        queue<Vertex> que;\n        vector<int>\
    \ cnt(m_vertex_size, 0);\n        for(auto v : source()) que.push(v);\n      \
    \  while(que.size()){\n            Vertex v = que.front(); que.pop();\n      \
    \      ret.push_back(v);\n            for(int u : m_adj[v]){\n               \
    \ if(++cnt[u] == indegree(u)) que.push(u);\n            }\n        }\n       \
    \ return ret;\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u304B\u3089\u8FBA\
    \u96C6\u5408\u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @note \u8FBA\u96C6\u5408\
    \u306F\u91CD\u307F\u3067\u6607\u9806\u30BD\u30FC\u30C8\u3055\u308C\u305F\u72B6\
    \u614B\u3067\u8FD4\u3055\u308C\u308B\u3002\n     * @return vector<Edge<CostType>>\
    \ \u8FBA\u96C6\u5408\n     */\n    vector<Edge<CostType>> edge_set(){\n      \
    \  vector<Edge<CostType>> ret;\n        vector<int> es(m_edge_size, 0);\n    \
    \    for(int i = 0; i < m_vertex_size; ++i){\n            for(auto e : m_adj[i]){\n\
    \                if(es[e.id]) continue;\n                es[e.id] = 1;\n     \
    \           ret.push_back(e);\n            }\n        }\n        sort(ret.begin(),\
    \ ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost\
    \ < r.cost;\n        });\n        return ret;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(){\n        int n = m_vertex_size;\n        vector<vector<CostType>>\
    \ ret(n, vector<CostType>(n, INF));\n        for(int i = 0; i < n; ++i) ret[i][i]\
    \ = 0;\n        for(int v = 0; v < n; ++v){\n            for(auto &e : m_adj[v]){\n\
    \                ret[v][e.to] = e.cost;\n            }\n        }\n        return\
    \ ret;\n    }\n\n    friend ostream &operator<<(ostream &os, Graph<CostType> &G){\n\
    \        for(int i = 0; i < G.size(); ++i){\n            os << \"Vertex \" <<\
    \ i << \" : \";\n            if(G[i].empty()){\n                os << \"<none>\"\
    \ << endl;\n                continue;\n            }\n            for(auto &e\
    \ : G[i]){\n                if(G.is_weighted()) os << \"{\" << e.to << \", \"\
    \ << e.cost << \"} \";\n                else os << e.to << \" \";\n          \
    \  }\n            if(i + 1 < G.size()) os << endl;\n        }\n        return\
    \ os;\n    }\n\n    vector<Edge<CostType>> &operator[](Vertex v){\n        return\
    \ get_adj(v);\n    }\n};\n#line 10 \"library/Graph/LongestDistance.hpp\"\n\ntemplate<typename\
    \ CostType>\nvector<CostType> longestdistance(Graph<CostType> &G, CostType INF,\
    \ Vertex start = -1, CostType init = 0){\n    vector<CostType> dp(G.size(), INF);\n\
    \    if(start == -1){\n        for(auto v : G.source()) dp[v] = init;\n    }\n\
    \    else dp[start] = init;\n    for(int i : G.topological_sort()){\n        if(dp[i]\
    \ == INF) continue;\n        for(auto &e : G[i]){\n            dp[e.to] = max(dp[e.to],\
    \ dp[i] + e.cost);\n        }\n    }\n    return dp;\n}\n"
  code: "/**\n * @file LongestDistance.hpp\n * @author log K (lX57)\n * @brief Longest\
    \ Distance - DAG\u306B\u304A\u3051\u308B\u6700\u9577\u8DDD\u96E2\n * @version\
    \ 1.0\n * @date 2024-02-11\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename\
    \ CostType>\nvector<CostType> longestdistance(Graph<CostType> &G, CostType INF,\
    \ Vertex start = -1, CostType init = 0){\n    vector<CostType> dp(G.size(), INF);\n\
    \    if(start == -1){\n        for(auto v : G.source()) dp[v] = init;\n    }\n\
    \    else dp[start] = init;\n    for(int i : G.topological_sort()){\n        if(dp[i]\
    \ == INF) continue;\n        for(auto &e : G[i]){\n            dp[e.to] = max(dp[e.to],\
    \ dp[i] + e.cost);\n        }\n    }\n    return dp;\n}"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/LongestDistance.hpp
  requiredBy: []
  timestamp: '2024-03-08 02:07:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Graph/LongestDistance.hpp
layout: document
redirect_from:
- /library/library/Graph/LongestDistance.hpp
- /library/library/Graph/LongestDistance.hpp.html
title: "Longest Distance - DAG\u306B\u304A\u3051\u308B\u6700\u9577\u8DDD\u96E2"
---