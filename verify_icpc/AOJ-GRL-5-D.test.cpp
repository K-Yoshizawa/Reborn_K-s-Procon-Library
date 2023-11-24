#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../icpc/HeavyLightDecomposition.hpp"

struct segtree{
    int sz, ofs;
    vl dat;
    ll e;

    ll merge(ll x, ll y){
        return x + y;
    }

    ll subquery(int ql, int qr, int l, int r, int i){
        if(qr <= l || r <= ql) return e;
        if(ql <= l && r <= qr) return dat[i];
        int m = (l + r) / 2;
        ll al = subquery(ql, qr, l, m, i * 2);
        ll ar = subquery(ql, qr, m, r, i * 2 + 1);
        return merge(al, ar);
    }
    
    segtree(vl &init) : e(0){
        sz = 1;
        while(sz < init.size()) sz <<= 1;
        ofs = sz - 1;
        dat.resize(sz * 2, e);
        for(int i = 0; i < init.size(); ++i) dat[sz + i] = init[i];
        for(int i = ofs; i >= 1; --i) dat[i] = merge(dat[i * 2], dat[i * 2 + 1]);
    }

    void update(int k, ll v){
        k += ofs;
        dat[k] = v;
        while(k >>= 1) dat[k] = merge(dat[k * 2], dat[k * 2 + 1]);
    }

    ll query(int l, int r){
        return subquery(l, r, 1, sz + 1, 1);
    }

    ll get(int k){
        return dat[k + ofs];
    }
};

int main(){
    int n; cin >> n;
    Graph G(n);
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int c; cin >> c;
            G[i].push_back({c, 1});
            G[c].push_back({i, 1});
        }
    }

    hld HLD(G);
    vi p = HLD.location();
    vl init(n, 0);
    segtree seg(init);

    int q; cin >> q;
    for(int i = 0; i < q; ++i){
        int com; cin >> com;
        if(com == 0){
            int v, w; cin >> v >> w;
            seg.update(p[v], seg.get(p[v]) + w);
        }
        else{
            int u; cin >> u;
            ll ans = 0;
            for(auto [l, r] : HLD.pathquery(u)){
                ans += seg.query(l, r);
            }
            cout << ans << endl;
        }
    }
}