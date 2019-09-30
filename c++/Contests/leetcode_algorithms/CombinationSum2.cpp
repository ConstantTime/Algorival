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
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
      int n = a.size();      
      vector < vector < int > > ans;
      vector < int > res;
      int cur = 0;
      doit(ans , res , a , cur , target , 0);
      set < vector < int > > check;
      for(auto j : ans) {
        check.insert(j);
      }
      ans.clear();
      for(auto j : check) {
        ans.push_back(j);
      }
      return ans;
    }
    void doit(vector < vector < int > > &ans , vector < int > &res , 
      vector < int > a , int &cur , int target , int i) {
      
      if(cur == target) {
        sort(res.begin(), res.end());
        ans.push_back(res);
        return ;
      }
      if(i >= a.size()) {
          return;
      }
      if(cur > target) return ;
        // cout << cur << " -> ";
        // for(auto j : res) cout << j << " ";
        // cout << endl;
      doit(ans , res , a , cur , target , i + 1);
      res.push_back(a[i]);
      cur += a[i];
      doit(ans , res , a , cur , target , i + 1);
      res.pop_back();
      cur -= a[i];
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}