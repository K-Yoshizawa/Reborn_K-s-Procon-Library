---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/UnionFind.hpp
    title: "UnionFind - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020"
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: library/Graph/Kruskal.hpp
    title: "Kruskal - \u6700\u5C0F\u5168\u57DF\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/minimum_spanning_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"verify/LC-MinimumSpanningTree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\n\n#line 1 \"library/Graph/Kruskal.hpp\"\
    \n/**\n * @file Kruskal.hpp\n * @brief Kruskal - \u6700\u5C0F\u5168\u57DF\u6728\
    \n * @version 3.1\n * @date 2024-02-11\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
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
    \ &operator[](Vertex v){\n        return get_adj(v);\n    }\n};\n#line 2 \"library/DataStructure/UnionFind.hpp\"\
    \n\n/**\n * @file UnionFind.hpp\n * @author log K (lX57)\n * @brief UnionFind\
    \ - \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\n * @version 2.0\n * @date\
    \ 2023-11-12\n */\n\n#line 12 \"library/DataStructure/UnionFind.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T = int>\nstruct UnionFind{\n    private:\n    vector<int>\
    \ __Data;\n    vector<T> __Weight;\n\n    T __weight(int k){\n        find(k);\n\
    \        return __Weight[k];\n    }\n\n    public:\n    /**\n     * @brief \u8981\
    \u7D20\u6570 `Size`, \u521D\u671F\u91CD\u307F `Init_Weight` \u3067UnionFind\u3092\
    \u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Size \u8981\u7D20\u6570\n\
    \     * @param Init_Weight \u91CD\u307F\u4ED8\u304DUnionFind\u306E\u521D\u671F\
    \u91CD\u307F (option, default = 0)\n     */\n    UnionFind(int Size, T Init_Weight\
    \ = 0) : __Data(Size, -1), __Weight(Size, Init_Weight) {}\n\n    /**\n     * @brief\
    \ \u8981\u7D20 `k` \u306E\u89AA\u3092\u8FD4\u3059\u3002\u3064\u3044\u3067\u306B\
    \u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\u308B\u3002\n     * @param k \u63A2\u7D22\
    \u3059\u308B\u8981\u7D20\n     * @return int \u89AA\u8981\u7D20\u306E\u756A\u53F7\
    \n     */\n    int find(int k){\n        if(__Data[k] < 0) return k;\n       \
    \ int r = find(__Data[k]);\n        __Weight[k] += __Weight[__Data[k]];\n    \
    \    return __Data[k] = r;\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\
    \u8981\u7D20 `y` \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n     */\n    bool same(int x, int\
    \ y){\n        return find(x) == find(y);\n    }\n\n    /**\n     * @brief `Weight(y)\
    \ - Weight(x)` \u3092\u8A08\u7B97\u3059\u308B\u3002\n     * @return T `Weight(y)\
    \ - Weight(x)` \u306E\u5024\n     */\n    T diff(int x, int y){\n        return\
    \ __weight(y) - __weight(x);\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x`\
    \ \u3068\u8981\u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\u91CD\u307F\u3092\
    \u4ED8\u4E0E\u3059\u308B\u3053\u3068\u3082\u3067\u304D\u308B\u3002\n     * @param\
    \ w `Weight(y) - Weight(x) = w` \u3068\u3044\u3046\u5236\u7D04\u6761\u4EF6 (option,\
    \ default = 0)\n     * @return \u4F75\u5408\u6E08\u306E\u5834\u5408\u306F `false`\
    \ \u3092\u8FD4\u3059\u3002\n     */\n    bool unite(int x, int y, T w = 0){\n\
    \        w += __weight(x) - __weight(y);\n        x = find(x), y = find(y);\n\
    \        if(x == y) return false;\n        if(__Data[x] > __Data[y]) swap(x, y),\
    \ w = -w;\n        __Data[x] += __Data[y];\n        __Data[y] = x;\n        __Weight[y]\
    \ = w;\n        return true;\n    }\n\n    vector<vector<int>> group(){\n    \
    \    vector<vector<int>> ret(__Data.size());\n        for(int i = 0; i < __Data.size();\
    \ ++i){\n            ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n};\n#line 10 \"library/Graph/Kruskal.hpp\"\n\ntemplate<typename\
    \ CostType>\nstruct Kruskal{\n    private:\n    Graph<CostType> &G;\n    vector<int>\
    \ m_used;\n    CostType m_ans;\n\n    public:\n    Kruskal(Graph<CostType> &G)\
    \ : G(G){\n        m_ans = 0;\n        UnionFind uf(G.size());\n        auto es\
    \ = G.edge_set();\n        for(auto &e : es){\n            int i = e.id;\n   \
    \         if(uf.same(e.from, e.to)) continue;\n            uf.unite(e.from, e.to);\n\
    \            m_used.push_back(i);\n            m_ans += e.cost;\n        }\n \
    \   }\n\n    vector<int> &get(){\n        return m_used;\n    }\n\n    CostType\
    \ val(){\n        return m_ans;\n    }\n};\n#line 4 \"verify/LC-MinimumSpanningTree.test.cpp\"\
    \n\nint main(){\n    int N, M; cin >> N >> M;\n    Graph<long long> G(N);\n  \
    \  G.input(M, true, true);\n\n    Kruskal kr(G);\n    auto ans = kr.get();\n \
    \   cout << kr.val() << endl;\n    for(auto i : ans){\n        cout << i << \"\
    \ \";\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
    \n\n#include \"../library/Graph/Kruskal.hpp\"\n\nint main(){\n    int N, M; cin\
    \ >> N >> M;\n    Graph<long long> G(N);\n    G.input(M, true, true);\n\n    Kruskal\
    \ kr(G);\n    auto ans = kr.get();\n    cout << kr.val() << endl;\n    for(auto\
    \ i : ans){\n        cout << i << \" \";\n    }\n    cout << endl;\n}"
  dependsOn:
  - library/Graph/Kruskal.hpp
  - library/Graph/GraphTemplate.hpp
  - library/DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: verify/LC-MinimumSpanningTree.test.cpp
  requiredBy: []
  timestamp: '2024-02-11 17:55:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-MinimumSpanningTree.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-MinimumSpanningTree.test.cpp
- /verify/verify/LC-MinimumSpanningTree.test.cpp.html
title: verify/LC-MinimumSpanningTree.test.cpp
---