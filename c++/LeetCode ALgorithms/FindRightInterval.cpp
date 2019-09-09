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
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
      vector < int > ans;
      int n = intervals.size();

      if(n == 0) {
        return ans;
      }      

      ans.resize(n);

      vector < pair < pair < int , int > , int > > a;

      rep(i , 0 , n - 1) {
        a.push_back({{intervals[i][0], intervals[i][1]} , i});
      }

      sort(a.begin(), a.end());

      rep(i , 0 , n - 1) ans[i] = -1;

      int l = 0;
      int r = n - 1;

      rep(i , 0 , n - 1) {
        pair < int , int > temp = {intervals[i][0], 
                                intervals[i][1]};
          
        l = 0;
        r = n - 1;
        while(l <= r) {
          int mid = (l + r) / 2;
          if(temp.second == a[mid].first.first && i != a[mid].second) {
            
            ans[i] = a[mid].second;
            break;
          }
          if(temp.second < a[mid].first.first) {
            ans[i] = a[mid].second;
            r = mid - 1;
          }
          else {
            l = mid + 1;
          }
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
