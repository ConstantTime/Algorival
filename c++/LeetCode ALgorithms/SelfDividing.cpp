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
    vector<int> selfDividingNumbers(int left, int right) {
      vector < int > ans;
      rep(i , left , right) {
        string s = to_string(i);

        bool flag = true;
        for(auto j : s) {
        
          if(j == '0') {
              flag = false;
              break;
          }
          if(i % (j - '0') != 0) flag = false;
        }

        if(flag) {
          ans.push_back(i); 
        }
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
