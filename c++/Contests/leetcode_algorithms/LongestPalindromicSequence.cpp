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
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n + 1][n + 1];
        rep(i , 0 , n) {
          rep(j , 0 , n) {
            dp[i][j] = 0;
          }
        }

        rep(i , 1 , n) {
          dp[i][i] = 1;
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
            }
          }
        }

        rep(i , 0 , n) {
          rep(j , 0 , n) {
            maxi = max(maxi , dp[i][j]);
          }
        }

        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
