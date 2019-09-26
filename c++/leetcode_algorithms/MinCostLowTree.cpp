#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
      int n = arr.size();

      if(n == 0) return 0;

      int dp[n][n];
      int a[n][n];

      rep(i , 0 , n - 1) {
        rep(j , 0 , n - 1) {
          dp[i][j] = 0;
        }
      }   

      rep(i , 1 , n) {
        a[i - 1][i - 1] = arr[i - 1];
      }

      rep(i , 0 , n - 2) {
        dp[i][i + 1] = arr[i] * arr[i + 1];
        a[i][i + 1] = max(arr[i] , arr[i + 1]);
      }

      rep(l , 2 , n) {
        per(i , n - l , 0) {
          int j = i + l - 1;

          dp[i][j] = INT_MAX;
          rep(k , i , j - 1) {
            dp[i][j] = min(dp[i][j] , a[i][k] * a[k + 1][j]
              + dp[i][k] + dp[k + 1][j]);

            a[i][j] = max(a[i][k] , a[k + 1][j]);
          }
        }
      }

      return dp[0][n - 1];
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
