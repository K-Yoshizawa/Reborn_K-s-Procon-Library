/**
 * @file Grid.hpp
 * @brief Grid
 * @version 0.1
 * @date 2024-04-29
 */

#include <bits/stdc++.h>
using namespace std;

struct Grid{
    int H_, W_;
    vector<string> G_;
    string Floor_{"."}, Wall_{"#"};
    vector<int> dy_{0, 1, 0, -1}, dx_{1, 0, -1, 0};

    bool in_(int y, int x){
        if(!(0 <= y and y < H_)) return false;
        if(!(0 <= x and x < W_)) return false;
        return true;
    }

    bool floor_(int y, int x){
        char c = G_[y][x];
        for(auto d : Floor_) if(c == d) return true;
        return false;
    }

    Grid(int H, int W) : H_(H), W_(W){}

    Grid(vector<string> &G) : G_(G), H_(G.size()), W_(G[0].size()){
        for(int i = 0; i < H_; ++i) assert(G_[i].size() == W_);
    }

    void input(){
        G_.resize(H_);
        for(int i = 0; i < H_; ++i){
            cin >> G_[i];
            assert(G_[i].size() == W_);
        }
    }

    int distance(pair<int, int> Start, pair<int, int> Goal){
        int inf = 1 << 28;
        vector dist(H_, vector<int>(W_, inf));
        dist[Start.first][Start.second] = 0;
        queue<pair<int, int>> que;
        que.emplace(Start);
        while(que.size()){
            auto [y, x] = que.front();
            int d = dist[y][x];
            que.pop();
            for(int i = 0; i < 4; ++i){
                int ny = y + dy_[i], nx = x + dx_[i];
                if(!in_(ny, nx)) continue;
                if(!floor_(ny, nx)) continue;
                if(d + 1 < dist[ny][nx]){
                    dist[ny][nx] = d + 1;
                    que.emplace(ny, nx);
                }
            }
        }
        return dist[Goal.first][Goal.second];
    }
};