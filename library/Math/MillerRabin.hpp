/**
 * @file MillerRabin.hpp
 * @brief Miller-Rabin - ミラーラビン素数判定法
 * @version 0.1
 * @date 2024-03-09
 */

#include "Montgomery.hpp"
#include <array>

bool MillerRabin(long long n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(!(n & 1)) return false;
    const array<long long, 7> as{2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    Montgomery::set_mod(n);
    long long s = 0, d = n - 1;
    while(!(d & 1)){
        ++s;
        d >>= 1;
    }
    for(auto a : as){
        Montgomery x = Montgomery(a).pow(d);
        if(x != 1 && x != 0){
            long long t;
            for(t = 0; t < s; ++t){
                if(x == n - 1) break;
                x *= x;
            }
            if(t == s) return false;
        }
    }
    return true;
}