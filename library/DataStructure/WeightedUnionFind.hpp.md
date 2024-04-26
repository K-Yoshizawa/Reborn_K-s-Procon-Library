---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-DSL-1-B.test.cpp
    title: verify/AOJ-DSL-1-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LC-Unionfind-Weighted.test.cpp
    title: verify/LC-Unionfind-Weighted.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Weighted UnionFind - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\
      \u30C7\u30FC\u30BF\u69CB\u9020"
    links: []
  bundledCode: "#line 2 \"library/DataStructure/WeightedUnionFind.hpp\"\n\n/**\n *\
    \ @file WeightedUnionFind.hpp\n * @author log K (lX57)\n * @brief Weighted UnionFind\
    \ - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\n\
    \ * @version 1.0\n * @date 2024-04-26\n */\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<typename T = int>\nstruct WeightedUnionFind{\n  \
    \  private:\n    vector<int> m_data;\n    vector<T> m_weight;\n\n    T __weight(int\
    \ k){\n        find(k);\n        return m_weight[k];\n    }\n\n    public:\n \
    \   /**\n     * @brief \u8981\u7D20\u6570 `Size`, \u521D\u671F\u91CD\u307F `Init_Weight`\
    \ \u3067WeightedUnionFind\u3092\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ Size \u8981\u7D20\u6570\n     * @param Init_Weight \u91CD\u307F\u4ED8\u304D\
    WeightedUnionFind\u306E\u521D\u671F\u91CD\u307F (option, default = 0)\n     */\n\
    \    WeightedUnionFind(int Size, T Init_Weight = 0) : m_data(Size, -1), m_weight(Size,\
    \ Init_Weight) {}\n\n    /**\n     * @brief \u8981\u7D20 `k` \u306E\u89AA\u3092\
    \u8FD4\u3059\u3002\u3064\u3044\u3067\u306B\u7D4C\u8DEF\u5727\u7E2E\u3092\u3059\
    \u308B\u3002\n     * @param k \u63A2\u7D22\u3059\u308B\u8981\u7D20\n     * @return\
    \ int \u89AA\u8981\u7D20\u306E\u756A\u53F7\n     */\n    int find(int k){\n  \
    \      if(m_data[k] < 0) return k;\n        int r = find(m_data[k]);\n       \
    \ m_weight[k] += m_weight[m_data[k]];\n        return m_data[k] = r;\n    }\n\n\
    \    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u304C\u540C\u3058\
    \u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\u3002\n     */\n    bool same(int x, int y){\n        return find(x) ==\
    \ find(y);\n    }\n\n    /**\n     * @brief `Weight(y) - Weight(x)` \u3092\u8A08\
    \u7B97\u3059\u308B\u3002\n     * @return T `Weight(y) - Weight(x)` \u306E\u5024\
    \n     */\n    T diff(int x, int y){\n        return __weight(y) - __weight(x);\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u3092\
    \u4F75\u5408\u3059\u308B\u3002\u91CD\u307F\u3092\u4ED8\u4E0E\u3059\u308B\u3053\
    \u3068\u3082\u3067\u304D\u308B\u3002\n     * @param w `Weight(y) - Weight(x) =\
    \ w` \u3068\u3044\u3046\u5236\u7D04\u6761\u4EF6 (option, default = 0)\n     *\
    \ @return \u4F75\u5408\u6E08\u306E\u5834\u5408\u306F `false` \u3092\u8FD4\u3059\
    \u3002\n     */\n    bool unite(int x, int y, T w = 0){\n        w += __weight(x)\
    \ - __weight(y);\n        x = find(x), y = find(y);\n        if(x == y) return\
    \ false;\n        if(m_data[x] > m_data[y]) swap(x, y), w = -w;\n        m_data[x]\
    \ += m_data[y];\n        m_data[y] = x;\n        m_weight[y] = w;\n        return\
    \ true;\n    }\n\n    vector<vector<int>> group(){\n        vector<vector<int>>\
    \ ret(m_data.size());\n        for(int i = 0; i < m_data.size(); ++i){\n     \
    \       ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file WeightedUnionFind.hpp\n * @author log K (lX57)\n\
    \ * @brief Weighted UnionFind - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\u30C7\
    \u30FC\u30BF\u69CB\u9020\n * @version 1.0\n * @date 2024-04-26\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T = int>\nstruct\
    \ WeightedUnionFind{\n    private:\n    vector<int> m_data;\n    vector<T> m_weight;\n\
    \n    T __weight(int k){\n        find(k);\n        return m_weight[k];\n    }\n\
    \n    public:\n    /**\n     * @brief \u8981\u7D20\u6570 `Size`, \u521D\u671F\u91CD\
    \u307F `Init_Weight` \u3067WeightedUnionFind\u3092\u521D\u671F\u5316\u3059\u308B\
    \u3002\n     * @param Size \u8981\u7D20\u6570\n     * @param Init_Weight \u91CD\
    \u307F\u4ED8\u304DWeightedUnionFind\u306E\u521D\u671F\u91CD\u307F (option, default\
    \ = 0)\n     */\n    WeightedUnionFind(int Size, T Init_Weight = 0) : m_data(Size,\
    \ -1), m_weight(Size, Init_Weight) {}\n\n    /**\n     * @brief \u8981\u7D20 `k`\
    \ \u306E\u89AA\u3092\u8FD4\u3059\u3002\u3064\u3044\u3067\u306B\u7D4C\u8DEF\u5727\
    \u7E2E\u3092\u3059\u308B\u3002\n     * @param k \u63A2\u7D22\u3059\u308B\u8981\
    \u7D20\n     * @return int \u89AA\u8981\u7D20\u306E\u756A\u53F7\n     */\n   \
    \ int find(int k){\n        if(m_data[k] < 0) return k;\n        int r = find(m_data[k]);\n\
    \        m_weight[k] += m_weight[m_data[k]];\n        return m_data[k] = r;\n\
    \    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\u7D20 `y` \u304C\
    \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u308B\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\u3002\n     */\n    bool same(int x, int y){\n        return\
    \ find(x) == find(y);\n    }\n\n    /**\n     * @brief `Weight(y) - Weight(x)`\
    \ \u3092\u8A08\u7B97\u3059\u308B\u3002\n     * @return T `Weight(y) - Weight(x)`\
    \ \u306E\u5024\n     */\n    T diff(int x, int y){\n        return __weight(y)\
    \ - __weight(x);\n    }\n\n    /**\n     * @brief \u8981\u7D20 `x` \u3068\u8981\
    \u7D20 `y` \u3092\u4F75\u5408\u3059\u308B\u3002\u91CD\u307F\u3092\u4ED8\u4E0E\u3059\
    \u308B\u3053\u3068\u3082\u3067\u304D\u308B\u3002\n     * @param w `Weight(y) -\
    \ Weight(x) = w` \u3068\u3044\u3046\u5236\u7D04\u6761\u4EF6 (option, default =\
    \ 0)\n     * @return \u4F75\u5408\u6E08\u306E\u5834\u5408\u306F `false` \u3092\
    \u8FD4\u3059\u3002\n     */\n    bool unite(int x, int y, T w = 0){\n        w\
    \ += __weight(x) - __weight(y);\n        x = find(x), y = find(y);\n        if(x\
    \ == y) return false;\n        if(m_data[x] > m_data[y]) swap(x, y), w = -w;\n\
    \        m_data[x] += m_data[y];\n        m_data[y] = x;\n        m_weight[y]\
    \ = w;\n        return true;\n    }\n\n    vector<vector<int>> group(){\n    \
    \    vector<vector<int>> ret(m_data.size());\n        for(int i = 0; i < m_data.size();\
    \ ++i){\n            ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](vector<int> &v){\n            return v.empty();\n        }), end(ret));\n\
    \        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2024-04-26 23:46:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LC-Unionfind-Weighted.test.cpp
  - verify/AOJ-DSL-1-B.test.cpp
documentation_of: library/DataStructure/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/library/DataStructure/WeightedUnionFind.hpp
- /library/library/DataStructure/WeightedUnionFind.hpp.html
title: "Weighted UnionFind - \u91CD\u307F\u4ED8\u304D\u7D20\u96C6\u5408\u30C7\u30FC\
  \u30BF\u69CB\u9020"
---