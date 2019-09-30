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
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector < pair < int , int > > res;
        rep(i , 0 , n - 1) {
          res.push_back({b[i] , i + 1});
        }
        sort(res.begin() , res.end());
        vector < int > ans(n);
        map < int , int > cnt;
        for(auto j : a) cnt[j]++;

        rep(i , 0 , n - 1) {
          int j = res[i].first;
          auto k = cnt.upper_bound(j);
          if(k == cnt.end()) break;
          ans[res[i].second - 1] = (*k).first;
          cnt[(*k).first]--;
          if(cnt[(*k).first] == 0) {
            cnt.erase((*k).first);
          }
          res[i].second *= -1;
        }

        auto j = cnt.begin();

        rep(i , 0 , n - 1) {
          if(res[i].second < 0) continue;
          ans[res[i].second - 1] = (*j).first;
          cnt[(*j).first]--;
          if(cnt[(*j).first] == 0) {
            j = next(j);
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
e