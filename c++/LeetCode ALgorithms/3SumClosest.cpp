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

ll power(ll a , ll b) {
    if(b == 0) return 1LL;
    ll d = power(a , b / 2);
    d *= d;
    d %= mod;

    if(b % 2 != 0) d *= a;

    d %= mod;

    return d;
}

ll inverse_mod(ll a) {
    return power(a , mod - 2);
}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();

      sort(nums.begin() , nums.end());
      int l = 0;
      int r = n - 1;
      int res = nums[0] + nums[1] + nums[2];
      int ans = 0;
      rep(i , 0 , n - 2) {
        l = i + 1;
        r = n - 1;
        while(l < r) {
          ans = nums[i] + nums[l] + nums[r];
          if(ans == target) return target;
          else if(ans < target) l++;
          else r--;
          if(abs(ans - target) < abs(res - target)) {
            res = ans;
          }
        }
      }

      return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
