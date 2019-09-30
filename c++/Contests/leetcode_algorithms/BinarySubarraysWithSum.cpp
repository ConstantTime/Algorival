#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int S) {
      int n = a.size();      
      int pre[n];
      pre[0] = a[0];
      rep(i , 1 , n - 1) {
        pre[i] = pre[i - 1] + a[i];
      }
      int cnt = 0;
      if(S != 0) {
        rep(i , 0 , n - 1) {
          if(pre[i] == S) cnt++;
        }

        unordered_map < int , int > res;
        for(auto j : pre) {
          res[j]++;
        }

        rep(i , 0 , n - 1) {
          cnt += res[pre[i] + S];
          cout << cnt << endl;
        }
      }
      else {
        int len = 0;
        rep(i , 0 , n - 1) {
          if(a[i] == S) cnt++;
        }
        cout << cnt << endl;
        rep(i , 0 , n - 1) {
          if(a[i] == 1) {
            cnt += (len * (len - 1)) / 2;
            len = 0;
          }
          else len++;
        }
        cnt += (len * (len - 1)) / 2;
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
