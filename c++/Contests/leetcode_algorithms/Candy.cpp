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

int a[N];

class Solution {
public:
    int candy(vector<int>& ratings) {
      int n = ratings.size();

      if(n == 0) return 0;
      int dp[n];

      dp[0] = 1;      

      for(int i = 1 ; i < n ; i++) {
        if(ratings[i] > ratings[i - 1]) {
          dp[i] = dp[i - 1] + 1;
        }
        else {
          dp[i] = 1;
        }
      }

      per(i , n - 2, 0) {
        if(ratings[i] > ratings[i + 1]) {
          dp[i] = max(dp[i] , dp[i + 1] + 1);
        }
      }

      int sum = 0;
      rep(i , 0 , n - 1) sum += dp[i];

      return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
