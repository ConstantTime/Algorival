#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 553456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int n;
int dp[1234][1234];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int n , k;
    cin >> n >> k;

    rep(i , 1 , n) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    rep(j , 1 , k) {
        dp[1][j] = j;
    }

    rep(i , 2 , n) {
        rep(j , 1 , k) {
            dp[i][j] = INT_MAX;
            int res = 0;
            rep(x , 1 , j) {
                res = 1 + max(dp[i - 1][x - 1] , dp[i][j - x]);
                if(res < dp[i][j]) {
                    dp[i][j] = res;
                }
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}
