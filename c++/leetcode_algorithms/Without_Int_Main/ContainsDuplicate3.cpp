#include <bits/stdc++.h>
using namespace std;
  
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)

const long long N = 153456;
const long long mod = 1e18 + 7;
const long double eps = 1e-6;
const long double pi = 3.1415926535;


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums , int k , int t) {
        int n = nums.size();
        set < ll > a;
        rep(i , 0 , n - 1) {
            if(i > k) {
                a.erase(nums[i - k - 1]);
            }
            auto pos = a.lower_bound((ll)((ll)nums[i] - (ll)t));
            if(pos != a.end() && *pos - nums[i] <= t) return true;
            a.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(12);
   
    return 0;
}
