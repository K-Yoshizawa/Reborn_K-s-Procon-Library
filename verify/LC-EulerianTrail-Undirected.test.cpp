#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"

#include "../library/Graph/EulerianTrail.hpp"

void solve(){
    int N, M; cin >> N >> M;
    Graph G(N, false);
    G.input(M, false, true);

    EulerianTrail et(G, M);
    if(et.exist()){
        cout << "Yes" << endl;
        for(auto v : et.trail_vertex()){
            cout << v << " ";
        }
        cout << endl;
        for(auto e : et.trail_edge()){
            cout << e << " ";
        }
        cout << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){
    int T; cin >> T;
    while(T--) solve();
}