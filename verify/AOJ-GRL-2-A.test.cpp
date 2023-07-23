#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include <bits/stdc++.h>

#include "../library/Graph/Kruskal.hpp"

using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    Graph<int> G(V);
    for(int i = 0; i < E; ++i){
        int s, t, w;
        cin >> s >> t >> w;
        G.add(s, t, w);
    }

    Kruskal<int> kr(G);
    cout << kr.Cost << endl;
}