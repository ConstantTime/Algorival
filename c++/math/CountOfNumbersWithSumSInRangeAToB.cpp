#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int n;
ll a , b;

ll dp[55][2005];

ll f(ll k , ll s) {
    if(k == 0) {
        return (s == 0);
    }
    if(dp[k][s] != -1) {
        return dp[k][s];
    }
    ll cnt = 0;
    for(ll d = 0 ; d <= 9 ; d++) {
        cnt += f(k - 1 , s - d);
    }
    dp[k][s] = cnt;
    return dp[k][s];
}

ll solve(ll x , ll s) {
    ll ret = 0;
    string cad = to_string(x);
    ll len = cad.length();
    ll sum = s;
    ll qued = len;
    rep(i , 0 , len - 1) {
        qued--;
        int d = cad[i] - '0';
        rep(j , 0 , d - 1) {
            if(sum - j >= 0) {
                ret += f(qued , sum - j);
            }
        }
        sum -= d;
    //    cout << x << " " << sum << endl;
    }
    return ret;
}

ll ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> a >> b;

    rep(i , 0 , 20) {
        rep(j , 0 , 170) dp[i][j] = -1;
    }

    rep(i , 1 , 162) {
//        cout << i << endl;
        ans[i] = solve(b + 1 , i) - solve(a , i);
    }

    // rep(i , 0 , 20) {
    //     cout << i << " " << ans[i] << endl;
    // }

    rep(i , 0 , 5) {
        rep(j , 0 , 5) cout << dp[i][j] << " ";
        cout << endl;
    }
    ll maxi = 1;
    rep(i , 0 , 162) {
        maxi = max(maxi , ans[i]);
    }

    ll cnt = 0;

    rep(i , 0 , 162) {
        if(ans[i] == maxi) cnt++;
    }

    cout << cnt << " " << maxi << endl;
   

    return 0;
}
