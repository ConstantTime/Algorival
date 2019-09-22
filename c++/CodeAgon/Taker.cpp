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

ll powerMod(ll a , ll b) {
    if(b == 0) return 1LL;
    ll d = powerMod(a , b / 2);
    d *= d;
    d %= mod;

    if(b % 2 != 0) d *= a;

    d %= mod;

    return d;
}

ll inverse_mod(ll a) {
    return powerMod(a , mod - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int q;
    cin >> q;

    while(q--) {
    	ll n;
    	cin >> n;

        // some problem still in the answer
        if(n <= 3) {
            cout << n << endl;
            continue;
        }
    	ll ans = 0;
    	ans = floor(log2(n));
  //      cout << ans << endl;
        ans += floor(log2((2 * n) / 3));
        cout << ans << endl;
    }
    
    return 0;
}
