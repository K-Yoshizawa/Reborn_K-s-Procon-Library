/**
 * @file Geometry.hpp
 * @brief Geometry - 幾何テンプレート
 * @version 0.1
 * @date 2024-07-19
 */

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const long double EPSl = 1e-18;

int sgn(double value){
    return (value < -EPS) ? -1 : (value > EPS) ? 1 : 0;
}

template<typename Type = double>
class Point{
    public:
    Type x, y;

    Point(Type x_ = 0, Type y_ = 0) : x(x_), y(y_){}

    double abs(){
        double cx = static_cast<double>(x);
        double cy = static_cast<double>(y);
        return sqrt(cx * cx + cy * cy);
    }

    long double absl(){
        long double cx = static_cast<long double>(x);
        long double cy = static_cast<long double>(y);
        return sqrtl(cx * cx + cy * cy);
    }

    Type dot(const Point &rp){
        return x * rp.x + y * rp.y;
    }

    Type det(const Point &rp){
        return x * rp.y - y * rp.x;
    }

    double arg(){
        double cx = static_cast<double>(x);
        double cy = static_cast<double>(y);
        return atan2(cy, cx);
    }

    long double argl(){
        long double cx = static_cast<long double>(x);
        long double cy = static_cast<long double>(y);
        return atan2l(cy, cx);
    }

    Point &operator+=(const Point &rp){
        x += rp.x, y += rp.y;
        return (*this);
    }

    Point &operator-=(const Point &rp){
        x -= rp.x, y -= rp.y;
        return (*this);
    }

    Point &operator*=(const Type &rv){
        x *= rv, y *= rv;
        return (*this);
    }

    Point &operator/=(const Type &rv){
        x /= rv, y /= rv;
        return (*this);
    }

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point &rp) const {
        return Point(*this) += rp;
    }

    Point operator-(const Point &rp) const {
        return Point(*this) -= rp;
    }

    Point operator*(const Point &rp) const {
        return Point(*this) *= rp;
    }

    Point operator*(const Type &rp) const {
        return Point(*this) *= rp;
    }

    Point operator/(const Type &rp) const {
        return Point(*this) /= rp;
    }

    Point &operator*=(const Point &rp){
        Type u = x, v = y;
        x = u * rp.x - v * rp.y, y = u * rp.y + v * rp.x;
        return (*this);
    }

    bool operator<(const Point &rp){
        if(sgn(x - rp.x)) return sgn(x - rp.x) < 0;
        return sgn(y - rp.y) < 0;
    }

    friend ostream &operator<<(ostream &os, const Point &p){
        return os << p.x << " " << p.y;
    }

    friend istream &operator>>(istream &is, Point &p){
        is >> p.x >> p.y;
        return (is);
    }
};

template<typename Type>
inline int iSP(Point<Type> a, Point<Type> b, Point<Type> c){
    if((b - a).det(c - a) > 0) return +1;
    if((b - a).det(c - a) < 0) return -1;
    if((b - a).dot(c - a) < 0) return -2;
    if((a - b).dot(c - b) < 0) return +2;
    return 0;
}

template<typename Type = double, bool Segment = false>
class Line{
    public:
    Point<Type> s, t;

    Line(Point<Type> s_, Point<Type> t_) : s(s_), t(t_){}

    bool is_segment(){
        return Segment;
    }

    double length(){
        return (t - s).abs();
    }

    Point<Type> v(){
        return (t - s);
    }

    Point<Type> e(){
        return v() / length();
    }
};

template<typename Type, bool S1, bool S2>
bool parallel(Line<Type, S1> &l1, Line<Type, S2> &l2){
    return sgn((l1.v()).det(l2.v())) == 0;
}

template<typename Type, bool S1, bool S2>
bool orthogonal(Line<Type, S1> &l1, Line<Type, S2> &l2){
    return sgn((l1.v()).dot(l2.v())) == 0;
}

template<typename Type, bool S1, bool S2>
bool intersect(Line<Type, S1> &l1, Line<Type, S2> &l2){
    if(S1 and S2){
        return !parallel(l1, l2);
    }
}