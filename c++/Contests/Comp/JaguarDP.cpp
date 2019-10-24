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

int n , m;
int dp[123][123];
int a[123][123];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n >> m;
    rep(i , 1 , n) {
        rep(j , 1 , m) cin >> a[i][j];
    }

    dp[0][0] = 1;
    rep(i , 1 , m) {
        if(dp[1][i - 1] == 0) {
            dp[1][i] = 0;
            continue;
        }
        if(a[1][i] == 1 || a[1][i] == 3) {
            dp[1][i] = 1;
        }
        else {
            dp[1][i] = 0;
        }
    }
    rep(i , 1 , n) {
        if(dp[i - 1][1] == 0) {
            dp[i][1] = 0;
            continue;
        }
        if(a[i][1] == 2 || a[i][1] == 3) {
            dp[i][1] = 1;
        }
        else {
            dp[i][1] = 0;
        }
    }

    rep(i , 2 , n) {
        rep(j , 2 , m) {
            ll x = dp[i - 1][j];
            ll y = dp[i][j - 1];
            dp[i][j] = (x + y) % mod;
        }
    }
    return 0;
}
