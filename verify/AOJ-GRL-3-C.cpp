// #define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_3_C"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/StronglyConnectedComponents.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph G(V, true);
    G.InputGraph(E, false, false);
    
    StronglyConnectedComponents scc(G);
    // auto cs = scc.get_components();
    // for(auto &vs : cs){
    //     cerr << "#";
    //     for(auto v : vs){
    //         cerr << " " << v;
    //     }
    //     cerr << endl;
    // }
    int Q; cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        cout << int(scc.BelongComponent(u) == scc.BelongComponent(v)) << endl;
    }
}