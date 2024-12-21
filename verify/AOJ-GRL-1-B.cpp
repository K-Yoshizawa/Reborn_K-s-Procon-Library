// #define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/BellmanFord.hpp"

int main(){
    int V, E, r; cin >> V >> E >> r;
    Graph<ll> G(V, true);
    G.InputGraph(E, true, false);
    
    BellmanFord bf(G, r);
    if(bf.Negative()){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for(int i = 0; i < V; ++i){
            if(bf.Reachable(i)){
                cout << bf.Distance(i) << endl;
            }
            else{
                cout << "INF" << endl;
            }
        }
    }
}