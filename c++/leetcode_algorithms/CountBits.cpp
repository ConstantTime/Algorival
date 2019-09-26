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
    int subarraySum(vector<int>& nums, int k) {
  		int n = nums.size();

  		int sum = 0;
  		int cnt = 0;

  		if(n == 0) return 0;

  		unordered_map < int , int > ans;

  		ans[0] = 1;
  		rep(i , 0 , n - 1) {
  			sum += nums[i];
  			if(ans.find(sum - k) != ans.end()) {
  				cnt += ans[sum - k];
  			}

  			ans[sum]++;
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
