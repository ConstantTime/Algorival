#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

long long bit1[N], bit2[N];
void U1(long long idx , long long x) {
        while (idx < N) {
            bit1[idx] += x;
            idx += (idx & -idx);
        }
}
void U2(long long idx , long long x) {
        while (idx < N) {
            bit2[idx] += x;
            idx += (idx & -idx);
        }
}
void update(long long u , long long v , long long w) {
        U1(u, w);
        U1(v + 1, -w);
        U2(u, w * (u - 1));
        U2(v + 1 , -w * v);
}
long long Q1(long long idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += bit1[idx];
            idx -= (idx & -idx);
        }
        return sum;
}
long long Q2(long long idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += bit2[idx];
            idx -= (idx & -idx);
        }
        return sum;
}
long long Q3(long long u) {
        return Q1(u) * u - Q2(u);
}
long long query(long long u , long long v) {
        return Q3(v) - Q3(u - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    return 0;
}
