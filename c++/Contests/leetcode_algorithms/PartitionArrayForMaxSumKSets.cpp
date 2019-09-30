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
    bool partition(vector < int > &nums , vector < bool > &vis , 
      int start , int k , int sum , int index , int target) {

      if(k == 1) return true;
      if(sum == target && index > 0) {
        return partition(nums , vis , 0 , k - 1 , 0 , 0 , target);
      }
      rep(i , start , nums.size() - 1) {
        if(vis[i] == false) {
          vis[i] = true;
          if(partition(nums , vis , i + 1 , k , 
            sum + nums[i] , index + 1 , target)) return true;

          vis[i] = false;
        }
      }
      return false;
    } 
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(auto j : nums) sum += j;
        if(k <= 0 || sum % k != 0) return false;
        vector < bool > vis(n , false);
        int jj = sum / k;
        return partition(nums , vis , 0 , k , 0 , 0 , jj); 
    } 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
