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

ll gcd(ll a , ll b) {
    return __gcd(a , b);
}
ll LCM(ll a , ll b) {
    return (a / gcd(a , b)) * b;
}
ll normalize(ll a , ll b) {
    a %= b;
    if(a < 0) a += b;
    return a;
} 
struct GCD_type {
    ll x;
    ll y;
    ll d;
};
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

ll a[N];
ll n[N];

pair < ll , ll > crt(int t) {
    pair < ll , ll > res;

    ll ans = a[1];
    ll lcm = n[1];

    rep(i , 2 , t) {
        auto pom = ex_GCD(lcm, n[i]);
        int x1 = pom.x;
        int d = pom.d;
        if((a[i] - ans) % d != 0) return {-1 , -1};
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
        lcm = LCM(lcm, n[i]);
    }

    res.first = ans;
    res.second = lcm;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int T;
    cin >> T;
    while(T--) {
        int t;
        t = 2;
        rep(i , 1 , t) cin >> a[i] >> n[i];
        pair < ll , ll > temp = crt(t);
        if(temp.first == -1 && temp.second == -1) {
            cout << "no solution" << endl;
            continue;
        }
        cout << temp.first << " " << temp.second << endl;
    }
    return 0;
}
