#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../Library/Template.hpp"
#include "../Library/Graph/Dijkstra.hpp"

int main(){
    int V, E, r; cin >> V >> E >> r;
    Dijkstra<ll, true> G(V);
    for(int i = 0; i < E; ++i){
        int s, t, d; cin >> s >> t >> d;
        G.AddEdge(s, t, d);
    }

    G.Solve(r);
    for(int i = 0; i < V; ++i){
        if(G.Reachable(i)){
            cout << G.Distance(i) << endl;
        }
        else{
            cout << "INF" << endl;
        }
    }
}