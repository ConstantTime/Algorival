#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int dp[n + 1][n + 1];
        int p[n + 1][n + 1];
        rep(i , 0 , n) {
          rep(j , 0 , n) {
            dp[i][j] = 0;
            p[i][j] = 0;
          }
        }

        rep(i , 1 , n) {
          dp[i - 1][i - 1] = 1;
        }

        int maxi = -1;

        rep(l , 2 , n) {
          rep(i , 0 , n - l) {
            int j = i + l - 1;
            if(s[i] == s[j] && l == 2) {
              dp[i][j] = 2;
            }
            else if(s[i] == s[j]) {
              dp[i][j] = 1 + dp[i + 1][j - 1] + 1;
            }
            else {
              dp[i][j] = max(dp[i][j - 1] , dp[i + 1][j]);
              p[i][j] = -1;
            }
          }
        }

        // rep(i , 0 , n - 1) {
        //     rep(j , 0 , n - 1) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int cnt = 0;
        rep(i , 0 , n - 1) {
          rep(j , 0 , n - 1) {
            if(i <= j && dp[i][j] == j - i + 1) {
            //  cout << i << " " << j << endl;
              cnt++;
            }
          }
        }

        return cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
