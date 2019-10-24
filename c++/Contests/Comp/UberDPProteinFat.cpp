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

int dp[55][555][555];
pair < int , int > a[55];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n , m;
    cin >> n >> m;

    rep(i , 1 , n) {
        cin >> a[i].first >> a[i].second;
    }

    dp[0][0][0] = 1;

    rep(i , 1 , n) {
        rep(j , 1 , 500) {
            rep(k , 1 , 500) {
                dp[i][j][k] = dp[i - 1][j][k];
                if(j - a[i].first >= 0 && k - a[i].second >= 0) {
                    if(dp[i - 1][j - a[i].first][k - a[i].second] == 1) {
                    //   cout << i << " " << j << " " << k << endl;
                        dp[i][j][k] = 1;
                    }
                }
            }
        }
    }

    rep(i , 1 , n) {
        rep(j , 1 , 500) {
            rep(k , 1 , 500) {
                // if(dp[i][j][k] == 1) {
                //     cout << i << " gg " << j << " " << k << endl;
                // }
                if(dp[i][j][k] == 1 && j % k == 0 && j / k == m) {
                    cout << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
