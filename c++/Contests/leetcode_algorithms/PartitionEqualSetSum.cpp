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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        bool a[n + 1][30001];

        int sum = 0;
        for(auto j : nums) {
          sum += j;
        }

        if(sum % 2 != 0) {
          return false;
        }

        sum = sum / 2;

        rep(i , 0 , n) {
          a[i][0] = true;
        }

        rep(i , 1 , sum) {
          a[0][i] = false;
        }

        rep(i , 1 , n) {
          rep(j , 1 , sum) {
            if(j < nums[i - 1]) {
              a[i][j] = a[i - 1][j];
            }
            else {
              a[i][j] = a[i - 1][j] || a[i - 1][j - nums[i - 1]];
            }
          }
        }

        return a[n][sum];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
e