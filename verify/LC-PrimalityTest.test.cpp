#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../library/Math/MillerRabin.hpp"

int main(){
    int Q; cin >> Q;
    while(Q--){
        long long N; cin >> N;
        cout << (MillerRabin(N) ? "Yes" : "No") << endl;
    }
}