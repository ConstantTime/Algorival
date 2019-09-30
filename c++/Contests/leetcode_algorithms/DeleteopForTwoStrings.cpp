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
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        int dp[m + 1][n + 1];

        rep(i , 0 , m) {
          rep(j , 0 , n) {
            dp[i][j] = 0;
          }
        }

        rep(i , 0 , m) {
          dp[i][0] = i;
        }

        rep(i , 0 , n) {
          dp[0][i] = i;
        }

        rep(i , 1 , m) {
          rep(j , 1 , n) {
            if(word1[i - 1] == word2[j - 1]) {
              dp[i][j] = dp[i - 1][j - 1];
            }
            else {
              dp[i][j] = 1 + min(dp[i - 1][j] , dp[i][j - 1]);
            }
          }
        }

        return dp[m][n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
