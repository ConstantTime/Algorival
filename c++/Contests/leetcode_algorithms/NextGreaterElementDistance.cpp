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
    vector<int> dailyTemperatures(vector<int>& T) {
      int n = T.size();

      vector < int > ans;

      if(n == 0) return ans;

      ans.resize(n);
      stack < pair < int , int > > s;

      s.push({T[0] , 0});
      rep(i , 1 , n - 1) {
        if(s.empty()) {
          s.push({T[i] , i});
          continue;
        }

        while(s.empty() == false && s.top().first < T[i]) {
          ans[s.top().second] = i - s.top().second;
          s.pop();
        }

        s.push({T[i] , i});
      } 

      while(s.empty() == false) {
        ans[s.top().second] = 0;
        s.pop();
      }      

      return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int t;
    cin >> t;

    while(t--) {
      ll n , m;

      cin >> n >> m;

      if(m < n - 1) {
        cout << -1 << endl;
        continue;
      }

      ll cnt = (ll)n * (ll)n;

      if(m > (n * (n + 1)) / 2) {
        cout << -1 << endl;
        continue;
      }

    }

    return 0;
}
