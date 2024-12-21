// #define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/WarshallFloyd.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph<ll> G(V, true);
    G.InputGraph(E, true, false);
    
    WarshallFloyd wf(G);
    wf.Print();
}