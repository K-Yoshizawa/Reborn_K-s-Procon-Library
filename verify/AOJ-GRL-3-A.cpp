// #define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_3_A"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/LowLink.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph<ll> G(V);
    G.InputGraph(E, false, false);
    
    LowLink lol(G);
    auto ans = lol.get_articulation_vertex();
    for(auto v : ans){
        cout << v << endl;
    }
}