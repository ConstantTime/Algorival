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

long long bit[N];
void update_internal(long long idx ,long long val) {
    while (idx < N) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

void update(long long a, long long b, long long val) {
    update_internal(a, val);
    update_internal(b + 1 , -val);
}

long long query(long long idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    return 0;
}
