/**
 * @file Montgomery.hpp
 * @brief Montgomery - モンゴメリ法
 * @version 0.1
 * @date 2024-03-09
 */

#include <iostream>
#include <cassert>
#include <cstdint>
using namespace std;

struct Montgomery{
    using mint = Montgomery;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static u64 MOD;
    static u64 INV_MOD;
    static u64 R;

    static u64 get_mod(){return MOD;}
    static void set_mod(u64 mod){
        assert(mod < (1LL << 62));
        assert(mod & 1);
        MOD = mod;
        R = -u128(mod) % mod;
        INV_MOD = get_inv_mod();
    }
    static u64 get_inv_mod(){
        u64 res = MOD;
        for(int i = 0; i < 5; ++i){
            res *= 2 - MOD * res;
        }
        return res;
    }
    static u64 reduct(const u128 &v){
        return (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;
    }

    u64 val;

    Montgomery() : val(0){}
    Montgomery(long long v) : val(reduct((u128(v) + MOD) * R)){}

    u64 get() const {
        u64 res = reduct(val);
        return res >= MOD ? res - MOD : res;
    }

    mint operator-() const {
        return mint() - mint(*this);
    }
    mint operator+(const mint &r) const {
        return mint(*this) += r;
    }
    mint operator-(const mint &r) const {
        return mint(*this) -= r;
    }
    mint operator*(const mint &r) const {
        return mint(*this) *= r;
    }
    mint &operator+=(const mint &r){
        if((val += r.val) >= 2 * MOD) val -= 2 * MOD;
        return (*this);
    }
    mint &operator-=(const mint &r){
        if((val += 2 * MOD - r.val) >= 2 * MOD) val -= 2 * MOD;
        return (*this);
    }
    mint &operator*=(const mint &r){
        val = reduct(u128(val) * r.val);
        return (*this);
    }
    mint &operator/=(const mint &r){
        (*this) *= r.inv();
        return (*this);
    }
    mint inv() const {
        return pow(MOD - 2);
    }
    mint pow(u128 k) const {
        mint ret(1), mul(*this);
        while(k){
            if(k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    bool operator==(const mint &r) const {
        return (val >= MOD ? val - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);
    }
    bool operator!=(const mint &r) const {
        return (val >= MOD ? val - MOD : val) != (r.val >= MOD ? r.val - MOD : r.val);
    }
    friend ostream &operator<<(ostream &os, const mint &x){
        return os << x.get();
    }
};

typename Montgomery::u64 Montgomery::MOD, Montgomery::INV_MOD, Montgomery::R;