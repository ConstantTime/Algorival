#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 353456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    ll n;
    cin >> n;

    ll ans = LLONG_MAX;
    rep(i , 1 , sqrt(n)) {
        if(n % i == 0) { 
            ll x = n / i;
            ll y = i;   
            ans = min(ans , x + y - 2);
        }
    }

    cout << ans << endl;
    return 0;
}
