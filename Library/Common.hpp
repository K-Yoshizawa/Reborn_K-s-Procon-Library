#pragma once

/**
 * @file Common.hpp
 */

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <type_traits>
using namespace std;

template<typename T>
T get_INF(){
    if constexpr (is_integral_v<T>){
        return numeric_limits<T>::max() >> 2;
    }
    else if constexpr (is_arithmetic_v<T>){
        return numeric_limits<T>::max() / 4.0;
    }
    else{
        return T();
    }
}
