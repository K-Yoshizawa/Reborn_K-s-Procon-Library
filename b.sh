#!/bin/bash

new_atcoder(){
    oj-bundle code.cpp > submit.cpp
    g++ submit.cpp -std=gnu++2a -O2 \
        -mtune=native -march=native -fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 \
        -I/opt/ac-library -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o a.out -lgmpxx -lgmp \
        -I/usr/include/eigen3
}

atcoder(){
    oj-bundle code.cpp > submit.cpp
    g++ submit.cpp -std=gnu++17 -O2 \
        -I/opt/ac-library -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o a.out
}

codeforces(){
    oj-bundle code.cpp > submit.cpp
    g++ submit.cpp -std=c++17 -O2 -o a.out
}

verify(){
    oj-bundle verify/$1.test.cpp > verify.cpp
    g++ verify.cpp -std=c++17 -O2 -DLOGK
}

verify_latest(){
    oj-bundle verify_latest/$1.test.cpp > verify.cpp
    g++ verify.cpp -std=c++17 -O2 -DLOGK
}

if [ $1 = "na" ]; then
    new_atcoder
elif [ $1 = "a" ]; then
    atcoder
elif [ $1 = "c" ]; then
    codeforces
elif [ $1 = "v" ]; then
    verify $2
elif [ $1 = "vl" ]; then
    verify_latest $2
elif [ $1 = "t" ]; then
    if [ $# = 1 ]; then
        ./a.out
    elif [ $2 = "id" ]; then
        ./a.out < in.txt
    elif [ $2 = "i" ]; then
        ./a.out < in.txt 2> deb.txt
    fi
fi
