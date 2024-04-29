#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../library/DataStructure/ConvexHullTrick.hpp"

using ll = int64_t;

int main(){
    int N, Q; cin >> N >> Q;
    ConvexHullTrick<ll> cht;
    for(int i = 0; i < N; ++i){
        ll a, b; cin >> a >> b;
        cht.insert(a, b);
    }
    while(Q--){
        int type; cin >> type;
        if(type == 0){
            ll a, b; cin >> a >> b;
            cht.insert(a, b);
        }
        else{
            ll p; cin >> p;
            cout << cht.query(p) << endl;
        }
    }
}