// #define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/Kruskal.hpp"

int main(){
    int N, M; cin >> N >> M;
    Graph<ll> G(N);
    G.InputGraph(M, true, false);

    Kruskal kr(G);
    cout << kr.get_cost() << endl;
    cout << kr.get_edge_id() << endl;
}