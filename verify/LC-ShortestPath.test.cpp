#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../Library/Template.hpp"
#include "../Library/Graph/Dijkstra.hpp"

int main(){
    int N, M, s, t; cin >> N >> M >> s >> t;
    Dijkstra<ll, true> G(N);
    for(int i = 0; i < M; ++i){
        int a, b; ll c; cin >> a >> b >> c;
        G.AddEdge(a, b, c);
    }

    G.Solve(s);
    if(!G.Reachable(t)){
        cout << -1 << endl;
        return 0;
    }
    auto P = G.Restore(t);
    cout << G.Distance(t) << ' ' << P.size() << endl;
    for(auto [s, t, w] : P){
        cout << s << ' ' << t << endl;
    }
}