---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/BinaryIndexedTreeDouble.hpp
    title: "Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248"
  - icon: ':question:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':warning:'
    path: library/Tree/HeavyLightDecomposition.hpp
    title: "Heavy Light Decomposition - HL\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
  bundledCode: "#line 1 \"verify/AOJ-GRL-5-E.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#line 2 \"library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n\n/**\n * @brief\
    \ Binary Indexed Tree (Double) - Range Add Query\u5BFE\u5FDC\u7248\n */\n\n#line\
    \ 2 \"library/DataStructure/BinaryIndexedTree.hpp\"\n\n/**\n * @brief Binary Indexed\
    \ Tree\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n/**\n * @brief\
    \ \u533A\u9593\u306B\u5BFE\u3059\u308B\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\
    \u548C\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u3057\u3066\u9AD8\u901F\u304B\u3064\
    \u7C21\u6613\u306B\u5B9F\u88C5\u3067\u304D\u308B\u30C7\u30FC\u30BF\u69CB\u9020\
    \u3002 \n */\ntemplate<typename T>\nstruct BinaryIndexedTree{\n    private:\n\
    \    vector<T> data;\n\n    public:\n    /**\n     * @brief Binary Indexed Tree\u3092\
    \u8981\u7D20\u6570size\u3001\u50240\u3067\u521D\u671F\u5316\u3059\u308B\u3002\n\
    \     * @param size \u914D\u5217\u306E\u8981\u7D20\u6570\n     */\n    BinaryIndexedTree(int\
    \ size){\n        data.resize(++size, 0);\n    }\n\n    BinaryIndexedTree() =\
    \ default;\n\n    /**\n     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u756A\
    \u53F7i\u306B\u5BFE\u3057\u3066\u3001\u914D\u5217\u306E\u6700\u521D\u304B\u3089\
    i\u307E\u3067\u306E\u9589\u533A\u9593\u306E\u548C\u3092\u6C42\u3081\u308B\u3002\
    \n     * @param i \u6C42\u3081\u305F\u3044\u9589\u533A\u9593\u53F3\u7AEF(1-index)\n\
    \     * @return T \u533A\u9593\u548C\n     */\n    T sum(int i){\n        T ret\
    \ = 0;\n        while(i > 0){\n            ret += data[i];\n            i -= i\
    \ & -i;\n        }\n        return ret;\n    }\n\n    /**\n     * @brief 1-index\u3067\
    \u8868\u3055\u308C\u308B\u756A\u53F7i\u306B\u5BFE\u3057\u3066\u3001data[i]\u306B\
    x\u3092\u52A0\u3048\u308B\u3002\n     * @param i \u52A0\u3048\u308B\u5834\u6240\
    \n     * @param x \u52A0\u3048\u308B\u5024\n     */\n    void add(int i, T x){\n\
    \        while(i < data.size()){\n            data[i] += x;\n            i +=\
    \ i & -i;\n        }\n    }\n\n    /**\n     * @brief 0-index\u3067\u8868\u3055\
    \u308C\u308B\u534A\u958B\u533A\u9593[l, r)\u306E\u533A\u9593\u548C\u3092\u6C42\
    \u3081\u308B\u3002\n     * @param l \u533A\u9593\u306E\u5DE6\u7AEF\n     * @param\
    \ r \u533A\u9593\u306E\u53F3\u7AEF\n     * @return T \u533A\u9593\u548C\n    \
    \ */\n    T query(int l, int r){\n        return sum(r) - sum(l);\n    }\n};\n\
    #line 8 \"library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n\ntemplate<typename\
    \ T>\nstruct BinaryIndexedTreeDouble{\n    private:\n    int sz;\n    BinaryIndexedTree<T>\
    \ BIT0, BIT1;\n\n    public:\n    BinaryIndexedTreeDouble(int size) : sz(size),\
    \ BIT0(size), BIT1(size){}\n\n    /**\n     * @brief 1-index\u3067\u8868\u3055\
    \u308C\u308B\u534A\u958B\u533A\u9593[left, right)\u306B\u5024x\u3092\u52A0\u7B97\
    \u3059\u308B\n     * @param left \u534A\u958B\u533A\u9593\u5DE6\u7AEF\n     *\
    \ @param right \u534A\u958B\u533A\u9593\u53F3\u7AEF\n     * @param x \u52A0\u7B97\
    \u3059\u308B\u5024\n     */\n    void add(int left, int right, T x){\n       \
    \ BIT0.add(left, -x * (left - 1));\n        BIT0.add(right, x * (right - 1));\n\
    \        BIT1.add(left, x);\n        BIT1.add(right, -x);\n    }\n\n    /**\n\
    \     * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u8981\u7D20i\u306B\u3064\u3044\
    \u3066\u3001\u8981\u7D201\u304B\u3089\u8981\u7D20i\u307E\u3067\u306E\u7DCF\u548C\
    \u3092\u8FD4\u3059\n     * @param i \u9589\u533A\u9593[1, i]\u306E\u53F3\u7AEF\
    \n     * @return T \u533A\u9593[1, i]\u306E\u7DCF\u548C\n     */\n    T sum(int\
    \ i){\n        return BIT0.sum(i) + BIT1.sum(i) * (T)i;\n    }\n\n    /**\n  \
    \   * @brief 1-index\u3067\u8868\u3055\u308C\u308B\u534A\u958B\u533A\u9593[left,\
    \ right)\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n     * @param left \u534A\u958B\u533A\
    \u9593\u5DE6\u7AEF\n     * @param right \u534A\u958B\u533A\u9593\u53F3\u7AEF\n\
    \     * @return T \u533A\u9593[left, right)\u306E\u7DCF\u548C\n     */\n    T\
    \ query(int left, int right){\n        return sum(right - 1) - sum(left - 1);\n\
    \    }\n};\n#line 2 \"library/Tree/HeavyLightDecomposition.hpp\"\n\n/**\n * @brief\
    \ Heavy Light Decomposition - HL\u5206\u89E3\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @brief Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\n\n#line 8 \"library/Graph/GraphTemplate.hpp\"\nusing namespace\
    \ std;\n\nusing EdgeNum = int;\nusing Vertex = int;\n\n/**\n * @brief \u30B0\u30E9\
    \u30D5\u306E\u8FBA\n */\ntemplate<typename CostType = int>\nstruct Edge{\n   \
    \ Vertex from, to;\n    CostType cost;\n\n    Edge(Vertex from, Vertex to, CostType\
    \ cost) : from(from), to(to), cost(cost){}\n};\n\n/**\n * @brief \u30B0\u30E9\u30D5\
    \u3092\u8868\u3059\u30AF\u30E9\u30B9\u3002\n * @note \u8FBA\u96C6\u5408\u306B\u3088\
    \u3063\u3066\u5B9F\u73FE\u3057\u3066\u3044\u308B\u3002\n * @tparam CostType \u8FBA\
    \u306E\u91CD\u307F\u306E\u578B\u3002\n */\ntemplate<typename CostType = int>\n\
    class Graph{\n    private:\n    int sz;\n    bool dir;\n    vector<int> indegree;\n\
    \n    public:\n    vector<Edge<CostType>> edges;\n    vector<vector<EdgeNum>>\
    \ connect;\n    vector<EdgeNum> rev; // \u5F62\u5F0F\u4E0A\u7121\u5411\u30B0\u30E9\
    \u30D5\u3067\u3082\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u306E\u3067\
    \u3001\u8FBA\u306E\u8FFD\u52A0\u6642\u306B\u9006\u8FBA\u306E\u8FBA\u756A\u53F7\
    \u3092\u8A18\u9332\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\n    CostType\
    \ INF;\n\n    /**\n     * @brief Construct a new Graph object\n     * @param VertexNum\
    \ \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\n     * @param isDirected \u6709\u5411\
    \u30B0\u30E9\u30D5\u3068\u3057\u3066\u4F5C\u6210\u3059\u308B\u304B\n     */\n\
    \    Graph(int VertexNum, bool isDirected = false) : sz(VertexNum), dir(isDirected),\
    \ connect(VertexNum), indegree(VertexNum), INF(numeric_limits<CostType>::max()){}\n\
    \n    Graph() = default;\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u306B\u9802\
    \u70B9s\u3068\u9802\u70B9t\u9593\u306E\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\
    \n     * @note \u6709\u5411\u30B0\u30E9\u30D5\u306A\u3089\u3070\u9802\u70B9s\u304B\
    \u3089\u9802\u70B9t\u3078\u306E\u6709\u5411\u8FBA\u3092\u3001\u7121\u5411\u30B0\
    \u30E9\u30D5\u306A\u3089\u3070\u9802\u70B9s\u3068\u9802\u70B9t\u3092\u7D50\u3076\
    \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * @param s \u9802\
    \u70B9s\n     * @param t \u9802\u70B9t\n     * @param w \u8FBA\u306E\u91CD\u307F\
    \ (option, default = 1)\n     */\n    void add(Vertex s, Vertex t, CostType w\
    \ = 1){\n        assert(0 <= s && s < sz);\n        assert(0 <= t && t < sz);\n\
    \        EdgeNum e = edges.size();\n        edges.push_back(Edge<CostType>(s,\
    \ t, w));\n        connect[s].push_back(e);\n        ++indegree[t];\n        if(!dir){\n\
    \            edges.push_back(Edge<CostType>(t, s, w));\n            connect[t].push_back(e\
    \ + 1);\n            rev.emplace_back(e + 1);\n            rev.emplace_back(e);\n\
    \        }\n    }\n\n    /**\n     * @brief \u6307\u5B9A\u3057\u305F\u8FBA\u756A\
    \u53F7\u306E\u8FBA\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param idx \u8FBA\
    \u756A\u53F7\n     * @return Edge<CostType> \u8FBA\u60C5\u5831\n     */\n    Edge<CostType>\
    \ get_edge(EdgeNum idx){\n        int e = edges.size();\n        assert(0 <= idx\
    \ && idx < e);\n        return edges[idx];\n    }\n\n    /**\n     * @brief \u6307\
    \u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\
    \u306E\u4E00\u89A7\u3092\u53D6\u5F97\u3059\u308B\u3002\n     * @param v \u9802\
    \u70B9\u756A\u53F7\n     * @return vector<Edge<CostType>> \u6307\u5B9A\u3057\u305F\
    \u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u306E\u4E00\u89A7\
    \n     */\n    vector<Edge<CostType>> get_edges(Vertex v){\n        assert(0 <=\
    \ v && v < sz);\n        vector<Edge<CostType>> ret;\n        for(auto &idx :\
    \ connect[v]) ret.push_back(get_edge(idx));\n        return ret;\n    }\n\n  \
    \  /**\n     * @brief \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\
    \u7D9A\u3059\u308B\u8FBA\u756A\u53F7\u306E\u4E00\u89A7\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return vector<EdgeNum>\
    \ \u6307\u5B9A\u3057\u305F\u9802\u70B9\u756A\u53F7\u306B\u63A5\u7D9A\u3059\u308B\
    \u8FBA\u756A\u53F7\u306E\u4E00\u89A7\n     */\n    vector<EdgeNum> get_list(Vertex\
    \ v){\n        assert(0 <= v && v < sz);\n        return connect[v];\n    }\n\n\
    \    /**\n     * @brief \u9006\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\
    \u3092\u4F5C\u6210\u3059\u308B\u3002\n     * @attention \u3053\u306E\u64CD\u4F5C\
    \u306F\u6709\u5411\u30B0\u30E9\u30D5\u306B\u306E\u307F\u53EF\u80FD\u3067\u3042\
    \u308B\u3002\n     * @return Graph<CostType> \u9006\u8FBA\u3092\u5F35\u3063\u305F\
    \u30B0\u30E9\u30D5\n     */\n    Graph<CostType> reverse(){\n        assert(dir);\n\
    \        Graph<CostType> ret(sz, true);\n        for(auto &e : edges){\n     \
    \       ret.add(e.to, e.from, e.cost);\n        }\n        return ret;\n    }\n\
    \n    inline size_t size(){\n        return sz;\n    }\n\n    inline bool directed(){\n\
    \        return dir;\n    }\n\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\
    \u306E\u6B21\u6570(\u51FA\u6B21\u6570)\u3092\u53D6\u5F97\u3059\u308B\u3002\n \
    \    * @note \u6709\u5411\u30B0\u30E9\u30D5\u306B\u304A\u3044\u3066\u3001\u7B2C\
    2\u5F15\u6570\u3092true\u306B\u3059\u308C\u3070\u5165\u6B21\u6570\u3092\u5F97\u308B\
    \u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param v \u9802\u70B9\u756A\
    \u53F7\n     * @param isIn (\u6709\u5411\u30B0\u30E9\u30D5\u306E\u3068\u304D\u306E\
    \u307F\u6709\u52B9)\u5165\u6B21\u6570\u3092\u53D6\u5F97\u3059\u308B\u304B (option,\
    \ default = false)\n     * @return int \u9802\u70B9v\u306E\u6307\u5B9A\u3057\u305F\
    \u5024\n     */\n    inline int degree(Vertex v, bool isIn = false){\n       \
    \ if(dir && isIn) return indegree[v];\n        return (int)connect[v].size();\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9802\u70B9root\u3092\
    \u6839\u3068\u3057\u305F\u7121\u5411\u6839\u4ED8\u304D\u6728\u3068\u307F\u306A\
    \u3057\u305F\u3068\u304D\u3001\u5404\u9802\u70B9\u306E\u89AA\u9802\u70B9\u306E\
    \u756A\u53F7\u3068\u3001\u305D\u308C\u3092\u7D50\u3076\u8FBA\u756A\u53F7\u3092\
    \u53D6\u5F97\u3059\u308B\u3002\n     * @attention \u30B0\u30E9\u30D5\u304C\u7121\
    \u5411\u6728\u3067\u306A\u3044\u5834\u5408\u306E\u52D5\u4F5C\u306F\u672A\u5B9A\
    \u7FA9\u3067\u3042\u308B\u3002\n     * @param root \u6728\u306E\u6839\u3068\u3059\
    \u308B\u9802\u70B9\u756A\u53F7\n     * @return vector<pair<Vertex, EdgeNum>> \u5404\
    \u9802\u70B9\u306E\u89AA\u306E\u9802\u70B9\u756A\u53F7\u3068\u89AA\u3078\u306E\
    \u8FBA\u756A\u53F7\uFF08\u9802\u70B9root\u306B\u5BFE\u3057\u3066\u306F\u3069\u3061\
    \u3089\u3082-1\u3068\u3059\u308B\uFF09\n     */\n    vector<pair<Vertex, EdgeNum>>\
    \ get_parent(Vertex root){\n        vector<pair<Vertex, EdgeNum>> ret(sz, pair<Vertex,\
    \ EdgeNum>(-1, -1));\n        stack<pair<Vertex, Vertex>> st;\n        st.emplace(root,\
    \ -1);\n        while(!st.empty()){\n            auto [v, parent] = st.top();\n\
    \            st.pop();\n            for(auto &idx : connect[v]){\n           \
    \     if(edges[idx].to == parent) continue;\n                ret[edges[idx].to]\
    \ = pair<Vertex, EdgeNum>(v, rev[idx]);\n                st.emplace(edges[idx].to,\
    \ v);\n            }\n        }\n        return ret;\n    }\n};\n#line 8 \"library/Tree/HeavyLightDecomposition.hpp\"\
    \n\ntemplate<typename CostType>\nstruct HeavyLightDecompsition{\n    using Column\
    \ = int;\n    \n    private:\n    int sz;\n    Vertex root;\n    Graph<CostType>\
    \ &G;\n    vector<int> subtree_size; // \u9802\u70B9i\u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\n    vector<pair<Vertex, EdgeNum>>\
    \ relation; // \u6728\u306E\u89AA\u5B50\u95A2\u4FC2\n    vector<vector<Vertex>>\
    \ column_vertex; // \u5404\u5217\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\u30EA\
    \u30B9\u30C8\n    vector<pair<Column, int>> column_index; // \u5404\u9802\u70B9\
    \u306E\u9802\u70B9\u30EA\u30B9\u30C8\u5185\u306E\u4F4D\u7F6E\n    vector<int>\
    \ offset; // 1\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\u3001\u5404\u5217\u306E\
    \u5148\u982D\u306E\u9802\u70B9\u306E\u4F4D\u7F6E (0-index)\n\n    /**\n     *\
    \ @brief \u9802\u70B9i\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u6570\u3092\u6C42\u3081\u308BDFS\n     * @param v \u6839\u3068\u306A\u308B\
    \u9802\u70B9\u756A\u53F7\n     * @param pre \u89AA\u306E\u9802\u70B9\n     * @return\
    \ int \u9802\u70B9\u306E\u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\n     */\n\
    \    int dfs1(Vertex v, Vertex pre){\n        int res = 0;\n        for(auto &e\
    \ : G.get_edges(v)){\n            if(e.to == pre) continue;\n            res +=\
    \ dfs1(e.to, v);\n        }\n        return subtree_size[v] = res + 1;\n    }\n\
    \n    void dfs2(Vertex v, Vertex pre, Column col){\n        if(column_vertex.size()\
    \ == col) column_vertex.emplace_back(vector<Vertex>{});\n        column_index[v]\
    \ = pair<Column, int>(col, column_vertex[col].size());\n        column_vertex[col].push_back(v);\n\
    \        Vertex next = -1;\n        int max_subtree = 0;\n        for(auto &e\
    \ : G.get_edges(v)){\n            if(e.to == pre) continue;\n            if(max_subtree\
    \ < subtree_size[e.to]){\n                next = e.to;\n                max_subtree\
    \ = subtree_size[e.to];\n            }\n        }\n        if(next != -1) dfs2(next,\
    \ v, col);\n        for(auto &e : G.get_edges(v)){\n            if(e.to == pre\
    \ || e.to == next) continue;\n            dfs2(e.to, v, column_vertex.size());\n\
    \        }\n        return;\n    }\n\n    /**\n     * @brief 1\u5217\u306B\u4E26\
    \u3079\u305F\u3068\u304D\u306E\u9802\u70B9v\u306E\u4F4D\u7F6E\n     * @param v\
    \ \u4F4D\u7F6E\u3092\u77E5\u308A\u305F\u3044\u9802\u70B9\u756A\u53F7\n     * @return\
    \ int \u5217\u306B\u304A\u3051\u308B\u4F4D\u7F6E(0-index)\n     */\n    inline\
    \ int locate(Vertex v){\n        auto [i, j] = column_index[v];\n        return\
    \ offset[i] + j;\n    }\n    \n    public:\n    HeavyLightDecompsition(Graph<CostType>\
    \ &G, Vertex root = 0) : G(G), sz(G.size()), root(root){\n        subtree_size.resize(sz,\
    \ -1);\n        dfs1(root, -1);\n        column_index.resize(sz, pair<Column,\
    \ int>(-1, -1));\n        dfs2(root, -1, 0);\n        offset.resize(column_vertex.size(),\
    \ 0);\n        for(int i = 1; i < column_vertex.size(); ++i){\n            offset[i]\
    \ = offset[i - 1] + column_vertex[i - 1].size();\n        }\n        relation\
    \ = G.get_parent(root);\n    }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\u3089\
    \u9802\u70B9v\u307E\u3067\u306E\u533A\u9593\u306E\u4E00\u89A7\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @note \u533A\u9593\u306F\u534A\u958B\u533A\u9593\u3068\
    \u3057\u3066\u4E0E\u3048\u3089\u308C\u3001\u9802\u70B9u\u3092\u7701\u7565\u3059\
    \u308B\u3068\u6839\u3068\u3059\u308B\n     * @param v: \u5B50\u306E\u65B9\u306E\
    \u9802\u70B9\u756A\u53F7(0-index)\n     * @param u: \u89AA\u306E\u65B9\u306E\u9802\
    \u70B9\u756A\u53F7(0-index, option default = root)\n     * @retval \u534A\u958B\
    \u533A\u9593\u306E\u4E00\u89A7\n     */\n    vector<pair<int, int>> get_segment(Vertex\
    \ v, Vertex u = -1){\n        if(u == -1) u = root;\n        auto [uc, ui] = column_index[u];\n\
    \        vector<pair<int, int>> ret;\n        Vertex now = v;\n        while(1){\n\
    \            auto [c, i] = column_index[now];\n            if(uc == c){\n    \
    \            ret.emplace_back(offset[uc] + ui, offset[c] + i + 1);\n         \
    \       break;\n            }\n            else ret.emplace_back(offset[c], offset[c]\
    \ + i + 1);\n            Vertex front = column_vertex[c][0];\n            now\
    \ = relation[front].first;\n        }\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u30921\u5217\u306B\u4E26\u3079\u305F\u3068\u304D\
    \u306E\u5404\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u5024\u306E\u914D\u5217\
    \u3092\u8FD4\u3059\n     * @note \u30BB\u30B0\u6728\u3068\u304B\u306E\u521D\u671F\
    \u914D\u5217\n     * @return vector<CostType> \n     */\n    vector<CostType>\
    \ get_data(){\n        vector<CostType> ret(sz, 0);\n        for(int i = 0; i\
    \ < column_vertex.size(); ++i){\n            for(int j = 0; j < column_vertex[i].size();\
    \ ++j){\n                Vertex v = column_vertex[i][j];\n                EdgeNum\
    \ e = relation[v].second;\n                if(e == -1) continue;\n           \
    \     ret[locate(v)] = G.get_edge(e).cost;\n            }\n        }\n       \
    \ return ret;\n    }\n};\n#line 5 \"verify/AOJ-GRL-5-E.cpp\"\n\nint main(){\n\
    \    int n;\n    cin >> n;\n    Graph<long long> G(n);\n    for(int i = 0; i <\
    \ n; ++i){\n        int k;\n        cin >> k;\n        for(int j = 0; j < k; ++j){\n\
    \            int c;\n            cin >> c;\n            G.add(i, c, 0);\n    \
    \    }\n    }\n\n    HeavyLightDecompsition<long long> HLD(G);\n    BinaryIndexedTreeDouble<long\
    \ long> BIT(n);\n\n    auto relation = G.get_parent(0);\n\n    int q;\n    cin\
    \ >> q;\n    while(q--){\n        int query;\n        cin >> query;\n        if(query\
    \ == 0){\n            int v, w;\n            cin >> v >> w;\n            auto\
    \ seg = HLD.get_segment(v);\n            for(auto &[s, t] : seg){\n          \
    \      BIT.add(s, t, w);\n            }\n            BIT.add(1, 2, -1);\n    \
    \    }\n        else{\n            int u;\n            cin >> u;\n           \
    \ auto seg = HLD.get_segment(u);\n            long long ans = 0;\n           \
    \ for(auto &[s, t] : seg){\n                ans += BIT.query(s, t);\n        \
    \    }\n            cout << ans << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\"\
    \n\n#include \"../library/DataStructure/BinaryIndexedTreeDouble.hpp\"\n#include\
    \ \"../library/Tree/HeavyLightDecomposition.hpp\"\n\nint main(){\n    int n;\n\
    \    cin >> n;\n    Graph<long long> G(n);\n    for(int i = 0; i < n; ++i){\n\
    \        int k;\n        cin >> k;\n        for(int j = 0; j < k; ++j){\n    \
    \        int c;\n            cin >> c;\n            G.add(i, c, 0);\n        }\n\
    \    }\n\n    HeavyLightDecompsition<long long> HLD(G);\n    BinaryIndexedTreeDouble<long\
    \ long> BIT(n);\n\n    auto relation = G.get_parent(0);\n\n    int q;\n    cin\
    \ >> q;\n    while(q--){\n        int query;\n        cin >> query;\n        if(query\
    \ == 0){\n            int v, w;\n            cin >> v >> w;\n            auto\
    \ seg = HLD.get_segment(v);\n            for(auto &[s, t] : seg){\n          \
    \      BIT.add(s, t, w);\n            }\n            BIT.add(1, 2, -1);\n    \
    \    }\n        else{\n            int u;\n            cin >> u;\n           \
    \ auto seg = HLD.get_segment(u);\n            long long ans = 0;\n           \
    \ for(auto &[s, t] : seg){\n                ans += BIT.query(s, t);\n        \
    \    }\n            cout << ans << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/BinaryIndexedTreeDouble.hpp
  - library/DataStructure/BinaryIndexedTree.hpp
  - library/Tree/HeavyLightDecomposition.hpp
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: verify/AOJ-GRL-5-E.cpp
  requiredBy: []
  timestamp: '2023-07-11 12:00:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/AOJ-GRL-5-E.cpp
layout: document
redirect_from:
- /library/verify/AOJ-GRL-5-E.cpp
- /library/verify/AOJ-GRL-5-E.cpp.html
title: verify/AOJ-GRL-5-E.cpp
---