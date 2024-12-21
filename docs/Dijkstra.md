---
title: Dijkstra - 単一始点最短経路問題 (ダイクストラ法)
documentation_of: ../Library/Graph/Dijkstra.hpp
---

# Dijkstra - 単一始点最短経路問題 (ダイクストラ法)

## Abstract

$V$ 頂点 $E$ 辺のグラフ $G$ について、単一始点最短経路問題をダイクストラ法を用いて時間計算量 $\textrm{O}((E + V) \log V)$ で解くアルゴリズムです。

## Constructor

```
Dijkstra<WeightType, isDirected = false>(int vertex_size)
```

- $V =$ `vertex_size` として、$V$ 頂点 $0$ 辺のグラフを作成します。
- テンプレート引数の `WeightType` で辺の重みの型を指定します。
- テンプレート引数の `isDirected` を `true` にすると有向グラフとして作成します。

### Constraints

- $0 \le V \le 10^6$

### Complexity

- $\textrm{O}(V)$

## AddEdge

```
void AddEdge(Vertex s, Vertex t, WeightType w)
```

- 無向グラフの場合、$2$ 頂点 $s, t$ 間に重み $w$ の無向辺を張ります。
- 有向グラフの場合、頂点 $s$ から頂点 $t$ に重み $w$ の有向辺を張ります。

### Constraints

- $0 \le s, t < V$
- $0 \le w$

### Complexity

- $\textrm{O}(1)$

## Solve

```
void Solve(Vertex source)
```

- 頂点 `source` を始点とした単一始点最短経路問題を解きます。

### Constraints

- $0 \le \textrm{source} < V$
- 予め `AddEdge()` で辺を追加してください。

### Complexity

- $\textrm{O}((E + V)\log V)$

## Distance

```
WeightType Distance(Vertex target)
```

- 頂点 `source` から頂点 `target` への最短経路を返します。
- 頂点 `target` に到達不可能の場合、$\infty$ が返されます。

### Constraints

- $0 \le \textrm{target} < V$
- 先に `Solve()` を呼び出さないときの動作は未定義です。

### Complexity

- $\textrm{O}(1)$

## Reachable

```
bool Reachable(Vertex target)
```

- 頂点 `source` から頂点 `target` に到達することが可能かを判定します。

### Constraints

- $0 \le \textrm{target} < V$
- 先に `Solve()` を呼び出さないときの動作は未定義です。

### Complexity

- $\textrm{O}(1)$

## Restore

```
vector<tuple<Vertex, Vertex, WeightType>> Restore(Vertex target)
```

- 頂点 `source` から頂点 `target` までの最短経路を復元します。
- 頂点 `target` に到達不可能の場合、空の列が返されます。
- 頂点 `target` に到達可能の場合、次の列が返されます。
    - 頂点 $v_1 =$ `source` $, v_{P + 1} =$ `target` の最短経路を $(v_1, v_2, \dots, v_{P + 1})$ とします。また、頂点 $x, y$ を結ぶ辺の重みを $w(x, y)$ とします。
    - このとき、$\lbrace (v_1, v_2, w(v_1, v_2)), (v_2, v_3, w(v_2, v_3)), \dots, (v_P, v_{P + 1}, w(v_P, v_{P + 1})) \rbrace$ の長さ $P$ の列を返します。

### Constraints

- $0 \le \textrm{target} < V$
- 先に `Solve()` を呼び出さないときの動作は未定義です。

### Complexity

- $\textrm{O}(V)$
