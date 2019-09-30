#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 1534;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

ll r[N];
ll c[N];
int a[N][N];

ll power(ll a , ll b) {
    if(b == 0) return 1LL;
    ll d = power(a , b / 2);
    d *= d;
    d %= mod;

    if(b % 2 != 0) d *= a;

    d %= mod;

    return d;
}

ll inverse_mod(ll a) {
    return power(a , mod - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    ll h , w;
    cin >> h >> w;

    rep(i , 1 , h) cin >> r[i]; 
    rep(i , 1 , w) cin >> c[i];

    ll ans = 0;

    rep(i , 1 , h) {
        rep(j , 1 , r[i]) {
            a[i][j] = 1;
        }
    }

    rep(i , 1 , w) {
        rep(j , 1 , c[i]) {
            a[j][i] = 1;
        }
    }

    bool flag = true;

    rep(i , 1 , h) {
        if(a[i][r[i] + 1] == 1) {
            flag = false;
        }
        a[i][r[i] + 1] = -1;
    }

    rep(i , 1 , w) {
        if(a[c[i] + 1][i] == 1) {
            flag = false;
        }
        a[c[i] + 1][i] = -1;
    }

    if(flag == false) {
        cout << 0 << endl;
        return 0;
    }

    // rep(i , 1 , h) {
    //     rep(j , 1 , w) {
    //         cout << a[i][j] << " ";
    //     } 
    //     cout << endl;
    // }

    ll cnt = 0;
    rep(i , 1 , h) {
        rep(j , 1 , w) {
            if(a[i][j] == 0) {
                cnt++;
            }
        }
    }

  //  cout << cnt << endl;
    ans = power(2LL , cnt);

    cout << ans << endl;
    return 0;
}
