---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: old/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify_old/AOJ-GRL-5-D.test.cpp
    title: verify_old/AOJ-GRL-5-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify_old/LC-VertexAddSubtreeSum.test.cpp
    title: verify_old/LC-VertexAddSubtreeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
    links: []
  bundledCode: "#line 1 \"old/Tree/EulerTour.hpp\"\n/**\n * @file EulerTour.hpp\n\
    \ * @author log K (lX57)\n * @brief Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n * @version 2.0\n * @date 2023-10-20\n */\n\n#line 2 \"old/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    EdgeID ID{-1};\n    Vertex src{-1}, to{-1};\n \
    \   CostType cost, cap;\n    EdgeIndex sidx, tidx;\n\n    Edge() = default;\n\
    \    Edge(EdgeID ID, Vertex src, Vertex to, CostType cost, CostType cap, EdgeIndex\
    \ sidx, EdgeIndex tidx) :\n        ID(ID), src(src), to(to), cost(cost), cap(cap),\
    \ sidx(sidx), tidx(tidx){}\n\n    void print(){\n        cerr << \"Edge \" <<\
    \ ID << \" : (\" << src << \" -> \" << to << \"), Cost = \" << cost << \", Capacity\
    \ = \" << cap << \", Place = [\" << sidx << \", \" << tidx << \"]\" << endl;\n\
    \    }\n};\n\ntemplate<typename CostType>\nusing EdgeSet = vector<Edge<CostType>>;\n\
    template<typename CostType>\nusing IncidentList = vector<vector<Edge<CostType>>>;\n\
    using AdjacentList = vector<vector<Vertex>>;\n\ntemplate<typename CostType>\n\
    struct Graph{\n    protected:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n\
    \    EdgeSet<CostType> __ES, __RES;\n    IncidentList<CostType> __IL;\n    AdjacentList\
    \ __AL;\n\n    public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected\
    \ = false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0),\
    \ __IL(VertexSize), __AL(VertexSize), INF(numeric_limits<CostType>::max() / 2){}\n\
    \n    Graph() = default;\n\n    void add(Vertex Source, Vertex To, CostType Cost\
    \ = 1){\n        assert(0 <= Source && Source < __CntVertex);\n        assert(0\
    \ <= To && To < __CntVertex);\n        EdgeIndex sidx = __IL[Source].size(), tidx\
    \ = __IL[To].size();\n        Edge<CostType> es{__CntEdge, Source, To, Cost, 1,\
    \ sidx, tidx};\n        Edge<CostType> et{__CntEdge, To, Source, Cost, 1, tidx,\
    \ sidx};\n        __ES.push_back(es);\n        __RES.push_back(et);\n        __IL[Source].push_back(es),\
    \ __AL[Source].push_back(To);\n        if(!__isDirected) __IL[To].push_back(et),\
    \ __AL[To].push_back(Source);\n        ++__CntEdge;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){\n      \
    \  vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));\n        for(Vertex\
    \ v = 0; v < __CntVertex; ++v){\n            ret[v][v] = 0;\n            for(auto\
    \ e : __IL[v]){\n                ret[v][e.to] = e.cost;\n            }\n     \
    \   }\n        return ret;\n    }\n\n    inline int vsize(){\n        return __CntVertex;\n\
    \    }\n\n    inline int esize(){\n        return __CntEdge;\n    }\n\n    inline\
    \ int incsize(Vertex v){\n        return __IL[v].size();\n    }\n\n    bool directed(){\n\
    \        return __isDirected;\n    }\n\n    inline EdgeSet<CostType> &get_edgeset(){\n\
    \        return __ES;\n    }\n\n    inline IncidentList<CostType> &get_incidentlist(){\n\
    \        return __IL;\n    }\n\n    inline vector<Edge<CostType>> &get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n \
    \   }\n\n    inline AdjacentList &get_adjacentlist(){\n        return __AL;\n\
    \    }\n\n    inline vector<Vertex> &get_adjacent(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
    \ operator[](Vertex v){\n        return get_incident(v);\n    }\n\n    void print_edgeset(bool\
    \ OneIndex = true){\n        for(int e = 0; e < __CntEdge; ++e){\n           \
    \ cout << e + OneIndex << \" : (\" << __ES[e].from + OneIndex << (__isDirected\
    \ ? \" -> \" : \" <-> \") << __ES[e].to + OneIndex << \") = \" << __ES[e].cost\
    \ << \" (\" << __ES[e].cap << \")\" << endl;\n        }\n    }\n\n    void print_incidentlist(bool\
    \ OneIndex = true){\n        for(int i = 0; i < __CntVertex; ++i){\n         \
    \   cout << i + OneIndex << \" :\";\n            for(int j = 0; j < __IL[i].size();\
    \ ++j){\n                cout << \" (\" << __IL[i][j].to << \" / \" << __IL[i][j].cost\
    \ << \", \" << __IL[i][j].cap << \")\";\n            }\n            cout << endl;\n\
    \        }\n    }\n\n    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n   \
    \     for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"old/Tree/EulerTour.hpp\"\
    \n\ntemplate<typename CostType>\nstruct EulerTour{\n    private:\n    Graph<CostType>\
    \ &G;\n    Vertex __Root;\n    vector<int> __In, __Out;\n    int __timer;\n\n\
    \    void __dfs(Vertex now, Vertex par){\n        __In[now] = __timer++;\n   \
    \     for(auto e : G.get_incident(now)){\n            if(e.to == par) continue;\n\
    \            __dfs(e.to, now);\n        }\n        __Out[now] = __timer++;\n \
    \   }\n\n    public:\n    /**\n     * @brief Euler Tour\u3092\u69CB\u7BC9\u3059\
    \u308B\u3002\n     * @param G \u69CB\u7BC9\u3059\u308B\u30B0\u30E9\u30D5\n   \
    \  * @param Root \u6839\u3068\u3059\u308B\u9802\u70B9\u756A\u53F7 (default = `0`)\n\
    \     * @note `timer` \u306F `1` \u304B\u3089\u59CB\u307E\u308B(\u30BB\u30B0\u6728\
    \u306A\u3069\u306B1-index\u3067\u8F09\u305B\u3089\u308C\u308B)\n     */\n    EulerTour(Graph<CostType>\
    \ &G, Vertex Root = 0) : G(G), __Root(Root), __In(G.vsize(), -1), __Out(G.vsize(),\
    \ -1){\n        __timer = 1;\n        __dfs(__Root, -1);\n    }\n\n    int in(Vertex\
    \ v){\n        assert(0 <= v && v < G.vsize());\n        return __In[v];\n   \
    \ }\n\n    int out(Vertex v){\n        assert(0 <= v && v < G.vsize());\n    \
    \    return __Out[v];\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\
    \ `in` \u3068 `out` \u3092\u540C\u6642\u306B\u53D6\u5F97\u3059\u308B\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return pair<int, int> `{in(v), out(v)}`\n\
    \     */\n    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v),\
    \ out(v));\n    }\n};\n"
  code: "/**\n * @file EulerTour.hpp\n * @author log K (lX57)\n * @brief Euler Tour\
    \ - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n * @version 2.0\n * @date 2023-10-20\n\
    \ */\n\n#include \"../Graph/GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct EulerTour{\n    private:\n    Graph<CostType> &G;\n    Vertex __Root;\n\
    \    vector<int> __In, __Out;\n    int __timer;\n\n    void __dfs(Vertex now,\
    \ Vertex par){\n        __In[now] = __timer++;\n        for(auto e : G.get_incident(now)){\n\
    \            if(e.to == par) continue;\n            __dfs(e.to, now);\n      \
    \  }\n        __Out[now] = __timer++;\n    }\n\n    public:\n    /**\n     * @brief\
    \ Euler Tour\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @param G \u69CB\u7BC9\
    \u3059\u308B\u30B0\u30E9\u30D5\n     * @param Root \u6839\u3068\u3059\u308B\u9802\
    \u70B9\u756A\u53F7 (default = `0`)\n     * @note `timer` \u306F `1` \u304B\u3089\
    \u59CB\u307E\u308B(\u30BB\u30B0\u6728\u306A\u3069\u306B1-index\u3067\u8F09\u305B\
    \u3089\u308C\u308B)\n     */\n    EulerTour(Graph<CostType> &G, Vertex Root =\
    \ 0) : G(G), __Root(Root), __In(G.vsize(), -1), __Out(G.vsize(), -1){\n      \
    \  __timer = 1;\n        __dfs(__Root, -1);\n    }\n\n    int in(Vertex v){\n\
    \        assert(0 <= v && v < G.vsize());\n        return __In[v];\n    }\n\n\
    \    int out(Vertex v){\n        assert(0 <= v && v < G.vsize());\n        return\
    \ __Out[v];\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E `in` \u3068\
    \ `out` \u3092\u540C\u6642\u306B\u53D6\u5F97\u3059\u308B\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @return pair<int, int> `{in(v), out(v)}`\n     */\n\
    \    pair<int, int> operator[](Vertex v){\n        return make_pair(in(v), out(v));\n\
    \    }\n};"
  dependsOn:
  - old/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: old/Tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2024-01-09 23:25:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify_old/LC-VertexAddSubtreeSum.test.cpp
  - verify_old/AOJ-GRL-5-D.test.cpp
documentation_of: old/Tree/EulerTour.hpp
layout: document
redirect_from:
- /library/old/Tree/EulerTour.hpp
- /library/old/Tree/EulerTour.hpp.html
title: "Euler Tour - \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---