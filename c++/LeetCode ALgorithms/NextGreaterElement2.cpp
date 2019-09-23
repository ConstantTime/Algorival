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
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        rep(i , 0 , n - 1) {
          a.push_back(a[i]);
        }

        stack < int > s;
        vector < int > ans;

        per(i , 2 * n - 1 , n) {
          s.push(a[i]);
        }

        per(i , n - 1 , 0) {
          while(!s.empty() && s.top() <= a[i]) {
            s.pop();
          }
          if(s.empty()) {
            ans.push_back(-1);
          }
          else {
            ans.push_back(s.top());
          }
          
          s.push(a[i]);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
