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
    vector<int> countBits(int num) {
      vector < int > ans;
      if(num == 0) return ans;

      int dp[num + 1];
      dp[0] = 0;
      
      int n = 1;

      while(n <= num) {
        for(int i = 0 ; i < n && i + n <= num ; i++) {
          dp[i + n] = dp[i] + 1;
        }

        n *= 2;
      }

      for(auto j : dp) {
        ans.push_back(j);
      }      

      return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
