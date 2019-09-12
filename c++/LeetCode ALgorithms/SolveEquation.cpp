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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        if(n <= 1) return false;

        rep(i , 0 , n - 2) {
            if(nums[i] == nums[i + 1]) {
                if(nums[i] == 0) return true;
            }
        }   

        if(k == 0) return false;
        if(k < 0) return checkSubarraySum(nums , -k);

        unordered_map < int , int > a;

        a[0] = -1;

        int sum = 0;

        rep(i , 0 , n - 1) {
            sum += nums[i];
            if(a.find(sum % k) != a.end()) {
                if(a[sum % k] < i - 1)
                    return true;
                else 
                    a[sum % k] = min((int)i , a[sum % k]);
            }
            else
                a[sum % k] = i;
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
