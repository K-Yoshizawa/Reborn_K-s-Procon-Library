// #define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_4_B"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/StronglyConnectedComponents.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph<int> G(V, true);
    G.InputGraph(E, false, false);
    
    StronglyConnectedComponents scc(G);
    auto vs = scc.TopologicalSort();
    for(auto v : vs){
        cout << v << endl;
    }
}