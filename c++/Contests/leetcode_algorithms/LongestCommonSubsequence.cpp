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
    int longestCommonSubsequence(string a, string b) {
        int m = a.length();
        int n = b.length();
        int maxi = -1;

        int dp[m + 1][n + 1];

        rep(i , 0 , m) {
          rep(j , 0 , n) {
            dp[i][j] = 0;
          }
        }

        rep(i , 1 , m) {
          rep(j , 1 , n) {
            if(a[i - 1] == b[j - 1]) {
              dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
              dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
          }
        }

        rep(i , 0 , m) {
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
