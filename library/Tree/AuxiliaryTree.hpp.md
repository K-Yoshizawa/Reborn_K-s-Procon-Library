---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Tree/EulerTour.hpp
    title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
  - icon: ':heavy_check_mark:'
    path: library/Tree/LowestCommonAncestor.hpp
    title: "Lowest Common Ancestor - \u6700\u5C0F\u5171\u901A\u7956\u5148"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Auxiliary Tree - \u88DC\u52A9\u6728"
    links: []
  bundledCode: "#line 1 \"library/Tree/AuxiliaryTree.hpp\"\n/**\n * @file AuxiliaryTree.hpp\n\
    \ * @brief Auxiliary Tree - \u88DC\u52A9\u6728\n * @version 1.0\n * @date 2024-02-11\n\
    \ */\n\n#line 1 \"library/Tree/EulerTour.hpp\"\n/**\n * @file EulerTour.hpp\n\
    \ * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n * @version\
    \ 3.0\n * @date 2024-02-11\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @brief Graph Template - \u30B0\u30E9\u30D5\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 3.0\n * @date 2024-01-09\n */\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Vertex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    public:\n    Vertex from, to;\n    CostType cost;\n\
    \    int loc{-1}, id{-1};\n\n    Edge() = default;\n    Edge(Vertex from, Vertex\
    \ to, CostType cost) : from(from), to(to), cost(cost){}\n\n    operator int(){\n\
    \        return to;\n    }\n};\n\ntemplate<typename CostType = int>\nstruct Graph{\n\
    \    private:\n    int m_vertex_size{0}, m_edge_size{0};\n    bool m_is_directed{false};\n\
    \    vector<vector<Edge<CostType>>> m_adj;\n    vector<int> m_indegree;\n\n  \
    \  public:\n    CostType INF{numeric_limits<CostType>::max() >> 2};\n\n    Graph()\
    \ = default;\n    Graph(int vertex_size, bool directed = false) : m_vertex_size(vertex_size),\
    \ m_is_directed(directed){\n        m_adj.resize(vertex_size);\n        m_indegree.resize(vertex_size,\
    \ 0);\n    }\n\n    void add(Vertex from, Vertex to, CostType cost = 1){\n   \
    \     assert(0 <= from and from < m_vertex_size);\n        assert(0 <= to and\
    \ to < m_vertex_size);\n        Edge<CostType> e1(from, to, cost);\n        e1.loc\
    \ = m_adj[from].size();\n        e1.id = m_edge_size;\n        m_adj[from].push_back(e1);\n\
    \        ++m_edge_size;\n        if(m_is_directed){\n            ++m_indegree[to];\n\
    \            return;\n        }\n        Edge<CostType> e2(to, from, cost);\n\
    \        e2.loc = m_adj[to].size();\n        e2.id = e1.id;\n        m_adj[to].push_back(e2);\n\
    \    }\n\n    void input(int edge_size, bool weighted = false, bool zero_index\
    \ = false){\n        for(int i = 0; i < edge_size; ++i){\n            Vertex s,\
    \ t; cin >> s >> t;\n            if(!zero_index) --s, --t;\n            CostType\
    \ c = 1;\n            if(weighted) cin >> c;\n            add(s, t, c);\n    \
    \    }\n    }\n\n    size_t size(){\n        return m_vertex_size;\n    }\n\n\
    \    int outdegree(Vertex v){\n        return (int)m_adj.at(v).size();\n    }\n\
    \n    int indegree(Vertex v){\n        if(m_is_directed) return m_indegree.at(v);\n\
    \        else return (int)m_adj.at(v).size();\n    }\n\n    vector<Vertex> source(){\n\
    \        assert(m_is_directed);\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 0) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Vertex> sink(){\n       \
    \ vector<Vertex> ret;\n        for(int i = 0; i < m_vertex_size; ++i){\n     \
    \       if(outdegree(i) == 0) ret.push_back(i);\n        }\n        return ret;\n\
    \    }\n\n    vector<Vertex> leaf(){\n        vector<Vertex> ret;\n        for(int\
    \ i = 0; i < m_vertex_size; ++i){\n            if(indegree(i) == 1) ret.push_back(i);\n\
    \        }\n        return ret;\n    }\n\n    vector<Edge<CostType>> &get_adj(Vertex\
    \ v){\n        return m_adj.at(v);\n    }\n\n    Graph<CostType> reverse(){\n\
    \        assert(m_is_directed);\n        Graph ret(m_vertex_size, true);\n   \
    \     for(auto es : m_adj){\n            for(auto e : es){\n                ret.add(e.to,\
    \ e.from, e.cost);\n            }\n        }\n        return ret;\n    }\n\n \
    \   vector<Vertex> topological_sort(){\n        assert(m_is_directed);\n     \
    \   vector<Vertex> ret;\n        queue<Vertex> que;\n        vector<int> cnt(m_vertex_size,\
    \ 0);\n        for(auto v : source()) que.push(v);\n        while(que.size()){\n\
    \            Vertex v = que.front(); que.pop();\n            ret.push_back(v);\n\
    \            for(int u : m_adj[v]){\n                if(++cnt[u] == indegree(u))\
    \ que.push(u);\n            }\n        }\n        return ret;\n    }\n\n    vector<Edge<CostType>>\
    \ edge_set(){\n        vector<Edge<CostType>> ret;\n        vector<int> es(m_edge_size,\
    \ 0);\n        for(int i = 0; i < m_vertex_size; ++i){\n            for(auto e\
    \ : m_adj[i]){\n                if(es[e.id]) continue;\n                es[e.id]\
    \ = 1;\n                ret.push_back(e);\n            }\n        }\n        sort(ret.begin(),\
    \ ret.end(), [&](Edge<CostType> &l, Edge<CostType> &r){\n            return l.cost\
    \ < r.cost;\n        });\n        return ret;\n    }\n\n    void print(){\n  \
    \      for(int i = 0; i < m_vertex_size; ++i){\n            cout << \"Vertex \"\
    \ << i << \" : \";\n            if(m_adj[i].empty()){\n                cout <<\
    \ \"<none>\" << endl;\n                continue;\n            }\n            for(auto\
    \ &e : m_adj[i]){\n                cout << \"{\" << e.to << \", \" << e.cost <<\
    \ \"} \";\n            }\n            cout << endl;\n        }\n    }\n\n    vector<Edge<CostType>>\
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};\n#line 9 \"library/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<int> m_in, m_out;\n\n    void m_dfs(Vertex v, Vertex p, int\
    \ &t){\n        m_in[v] = t++;\n        for(auto &e : G[v]){\n            if(e.to\
    \ == p) continue;\n            m_dfs(e.to, v, t);\n        }\n        m_out[v]\
    \ = t++;\n    }\n\n    public:\n    /**\n     * @brief Construct a new Euler Tour\
    \ object\n     * @param G \u6728\n     * @param Root \u6839\u306E\u9802\u70B9\u756A\
    \u53F7(0-index)\n     * @param Offset \u30BF\u30A4\u30E0\u30B9\u30BF\u30F3\u30D7\
    \u306E\u521D\u671F\u5024\n     */\n    EulerTour(Graph<CostType> &G, Vertex Root\
    \ = 0, int Offset = 0) : G(G){\n        m_in.resize(G.size());\n        m_out.resize(G.size());\n\
    \        m_dfs(Root, -1, Offset);\n    }\n\n    int in(Vertex v){\n        assert(0\
    \ <= v && v < G.size());\n        return m_in[v];\n    }\n\n    int out(Vertex\
    \ v){\n        assert(0 <= v && v < G.size());\n        return m_out[v];\n   \
    \ }\n\n    pair<vector<int>, vector<int>> get(){\n        return make_pair(m_in,\
    \ m_out);\n    }\n\n    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v),\
    \ out(v));\n    }\n};\n#line 1 \"library/Tree/LowestCommonAncestor.hpp\"\n/**\n\
    \ * @file LowestCommonAncestor.hpp\n * @brief Lowest Common Ancestor - \u6700\u5C0F\
    \u5171\u901A\u7956\u5148\n * @version 3.0\n * @date 2024-02-11\n */\n\n#line 9\
    \ \"library/Tree/LowestCommonAncestor.hpp\"\n\ntemplate<typename CostType>\nstruct\
    \ LowestCommonAncestor{\n    private:\n    Graph<CostType> &G;\n    int m_height;\n\
    \    vector<int> m_depth;\n    vector<vector<Vertex>> m_parent;\n\n    void m_dfs(Vertex\
    \ v, Vertex p, int d){\n        m_parent[0][v] = p;\n        m_depth[v] = d;\n\
    \        for(auto &e : G[v]){\n            if(e.to != p) m_dfs(e.to, v, d + 1);\n\
    \        }\n    }\n\n    public:\n    /**\n     * @brief Construct a new Lowest\
    \ Common Ancestor object\n     * @param G \u6728\n     * @param Root \u6839\u306E\
    \u9802\u70B9\u756A\u53F7(0-index)\n     */\n    LowestCommonAncestor(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), m_height(32){\n        m_depth.resize(G.size());\n\
    \        m_parent.resize(m_height, vector<Vertex>(G.size(), -1));\n        m_dfs(Root,\
    \ -1, 0);\n        for(int k = 0; k + 1 < m_height; ++k){\n            for(Vertex\
    \ v = 0; v < G.size(); ++v){\n                if(m_parent[k][v] < 0) m_parent[k\
    \ + 1][v] = -1;\n                else m_parent[k + 1][v] = m_parent[k][m_parent[k][v]];\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u9802\u70B9 `u` \u3068\
    \u9802\u70B9 `v` \u306E LCA \u3092\u6C42\u3081\u308B\u3002\n     * @note \u9802\
    \u70B9\u756A\u53F7\u306F 0-index\n     * @return Vertex LCA\u306E\u9802\u70B9\u756A\
    \u53F7\n     */\n    Vertex get(Vertex u, Vertex v){\n        if(m_depth[u] >\
    \ m_depth[v]) swap(u, v);\n        for(int k = 0; k < m_height; ++k){\n      \
    \      if((m_depth[v] - m_depth[u]) >> k & 1){\n                v = m_parent[k][v];\n\
    \            }\n        }\n        if(u == v) return u;\n        for(int k = m_height\
    \ - 1; k >= 0; --k){\n            if(m_parent[k][u] != m_parent[k][v]){\n    \
    \            u = m_parent[k][u];\n                v = m_parent[k][v];\n      \
    \      }\n        }\n        return m_parent[0][u];\n    }\n};\n#line 10 \"library/Tree/AuxiliaryTree.hpp\"\
    \n\ntemplate<typename CostType>\nstruct AuxiliaryTree{\n    private:\n    Graph<CostType>\
    \ &G;\n    vector<int> m_aux, m_ori, m_par;\n    EulerTour<CostType> m_et;\n \
    \   LowestCommonAncestor<CostType> m_lca;\n\n    public:\n    AuxiliaryTree(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), m_et(G, Root), m_lca(G, Root){\n        int n =\
    \ G.size();\n        m_aux.resize(n, -1);\n        m_ori.resize(n, -1);\n    \
    \    m_par.resize(n, -1);\n    }\n\n    /**\n     * @brief \u9802\u70B9\u96C6\u5408\
    \ `vs` \u3092\u542B\u3080\u88DC\u52A9\u6728 `T'` \u3092\u751F\u6210\u3059\u308B\
    \u3002\n     * @param vs \u9802\u70B9\u96C6\u5408\n     * @return Graph<CostType>\
    \ \u751F\u6210\u3057\u305F\u88DC\u52A9\u6728 `T'`\n     */\n    Graph<CostType>\
    \ build(vector<Vertex> &vs){\n        int m = vs.size();\n        sort(vs.begin(),\
    \ vs.end(), [&](int i, int j){\n            return m_et.in(i) < m_et.in(j);\n\
    \        });\n        for(int i = 0; i < m - 1; ++i){\n            vs.push_back(m_lca.get(vs[i],\
    \ vs[i + 1]));\n        }\n        sort(vs.begin(), vs.end(), [&](int i, int j){\n\
    \            return m_et.in(i) < m_et.in(j);\n        });\n        vs.erase(unique(vs.begin(),\
    \ vs.end()), vs.end());\n        m = vs.size();\n        for(int i = 0; i < m;\
    \ ++i) m_aux[vs[i]] = i, m_ori[i] = vs[i];\n        stack<Vertex> st;\n      \
    \  st.push(vs[0]);\n        for(int i = 1; i < m; ++i){\n            while(m_et.out(st.top())\
    \ < m_et.in(vs[i])) st.pop();\n            if(st.size()) m_par[vs[i]] = st.top();\n\
    \            st.push(vs[i]);\n        }\n        Graph ret(m);\n        for(int\
    \ i = 1; i < m; ++i){\n            ret.add(m_aux[m_par[vs[i]]], m_aux[vs[i]]);\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief \u88DC\u52A9\u6728\
    \ `T'` \u306B\u304A\u3051\u308B\u9802\u70B9 `v` \u304C\u5143\u306E\u6728 `T` \u306E\
    \u3069\u306E\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u304B\u3092\u8FD4\u3059\
    \u95A2\u6570\n     * @param v \u6700\u5F8C\u306B\u751F\u6210\u3057\u305F\u88DC\
    \u52A9\u6728 `T'` \u306B\u304A\u3051\u308B\u9802\u70B9 (0-index)\n     * @return\
    \ int \u5143\u306E\u6728 `T` \u306B\u304A\u3051\u308B\u9802\u70B9\u756A\u53F7\
    \ (0-index)\n     */\n    int recall(int v){\n        return m_ori[v];\n    }\n\
    \n    int operator[](int v){\n        return recall(v);\n    }\n};\n"
  code: "/**\n * @file AuxiliaryTree.hpp\n * @brief Auxiliary Tree - \u88DC\u52A9\u6728\
    \n * @version 1.0\n * @date 2024-02-11\n */\n\n#include \"EulerTour.hpp\"\n#include\
    \ \"LowestCommonAncestor.hpp\"\n\ntemplate<typename CostType>\nstruct AuxiliaryTree{\n\
    \    private:\n    Graph<CostType> &G;\n    vector<int> m_aux, m_ori, m_par;\n\
    \    EulerTour<CostType> m_et;\n    LowestCommonAncestor<CostType> m_lca;\n\n\
    \    public:\n    AuxiliaryTree(Graph<CostType> &G, Vertex Root = 0) : G(G), m_et(G,\
    \ Root), m_lca(G, Root){\n        int n = G.size();\n        m_aux.resize(n, -1);\n\
    \        m_ori.resize(n, -1);\n        m_par.resize(n, -1);\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9\u96C6\u5408 `vs` \u3092\u542B\u3080\u88DC\u52A9\u6728\
    \ `T'` \u3092\u751F\u6210\u3059\u308B\u3002\n     * @param vs \u9802\u70B9\u96C6\
    \u5408\n     * @return Graph<CostType> \u751F\u6210\u3057\u305F\u88DC\u52A9\u6728\
    \ `T'`\n     */\n    Graph<CostType> build(vector<Vertex> &vs){\n        int m\
    \ = vs.size();\n        sort(vs.begin(), vs.end(), [&](int i, int j){\n      \
    \      return m_et.in(i) < m_et.in(j);\n        });\n        for(int i = 0; i\
    \ < m - 1; ++i){\n            vs.push_back(m_lca.get(vs[i], vs[i + 1]));\n   \
    \     }\n        sort(vs.begin(), vs.end(), [&](int i, int j){\n            return\
    \ m_et.in(i) < m_et.in(j);\n        });\n        vs.erase(unique(vs.begin(), vs.end()),\
    \ vs.end());\n        m = vs.size();\n        for(int i = 0; i < m; ++i) m_aux[vs[i]]\
    \ = i, m_ori[i] = vs[i];\n        stack<Vertex> st;\n        st.push(vs[0]);\n\
    \        for(int i = 1; i < m; ++i){\n            while(m_et.out(st.top()) < m_et.in(vs[i]))\
    \ st.pop();\n            if(st.size()) m_par[vs[i]] = st.top();\n            st.push(vs[i]);\n\
    \        }\n        Graph ret(m);\n        for(int i = 1; i < m; ++i){\n     \
    \       ret.add(m_aux[m_par[vs[i]]], m_aux[vs[i]]);\n        }\n        return\
    \ ret;\n    }\n\n    /**\n     * @brief \u88DC\u52A9\u6728 `T'` \u306B\u304A\u3051\
    \u308B\u9802\u70B9 `v` \u304C\u5143\u306E\u6728 `T` \u306E\u3069\u306E\u9802\u70B9\
    \u306B\u5BFE\u5FDC\u3059\u308B\u304B\u3092\u8FD4\u3059\u95A2\u6570\n     * @param\
    \ v \u6700\u5F8C\u306B\u751F\u6210\u3057\u305F\u88DC\u52A9\u6728 `T'` \u306B\u304A\
    \u3051\u308B\u9802\u70B9 (0-index)\n     * @return int \u5143\u306E\u6728 `T`\
    \ \u306B\u304A\u3051\u308B\u9802\u70B9\u756A\u53F7 (0-index)\n     */\n    int\
    \ recall(int v){\n        return m_ori[v];\n    }\n\n    int operator[](int v){\n\
    \        return recall(v);\n    }\n};"
  dependsOn:
  - library/Tree/EulerTour.hpp
  - library/Graph/GraphTemplate.hpp
  - library/Tree/LowestCommonAncestor.hpp
  isVerificationFile: false
  path: library/Tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2024-02-11 23:48:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Tree/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/library/Tree/AuxiliaryTree.hpp
- /library/library/Tree/AuxiliaryTree.hpp.html
title: "Auxiliary Tree - \u88DC\u52A9\u6728"
---