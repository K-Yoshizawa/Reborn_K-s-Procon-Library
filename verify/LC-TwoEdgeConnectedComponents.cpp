// #define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Graph/TwoEdgeConnectedComponents.hpp"

int main(){
    int N, M; cin >> N >> M;
    Graph<int> G(N);
    G.InputGraph(M, false, false);

    TwoEdgeConnectedComponents<int> tecc(G);
    auto ans = tecc.get_components();
    cout << ans.size() << endl;
    for(auto &vs : ans){
        cout << vs.size();
        for(auto &v : vs){
            cout << " " << v;
        }
        cout << endl;
    }
}