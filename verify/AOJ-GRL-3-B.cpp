// #define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_3_B"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/LowLink.hpp"

int main(){
    int V, E; cin >> V >> E;
    Graph<int> G(V);
    G.InputGraph(E, false, false);
    
    LowLink lol(G);
    auto ans = lol.get_bridge();
    sort(ans.begin(), ans.end(), [](Edge<int> le, Edge<int> re){
        if(le.from == re.from) return le.to < re.to;
        return le.from < re.from;
    });
    for(auto e : ans){
        cout << e.from << " " << e.to << endl;
    }
}