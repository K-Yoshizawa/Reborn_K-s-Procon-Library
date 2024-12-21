// #define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#define IGNORE

#include "../Library/Template.hpp"
#include "../Library/Tree/HeavyLightDecomposition.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    RootedTree<int> T(N);
    T.InputGraphFormat(false, false);

    HeavyLightDecomposition hld(T);
    while(Q--){
        int s, t, i; cin >> s >> t >> i;
        cout << hld.Jump(s, t, i) << endl;
    }
}