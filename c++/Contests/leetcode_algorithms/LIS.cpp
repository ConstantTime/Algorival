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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int lis[n];
        int maxi = 1;
        rep(i , 0 , n - 1) {
            lis[i] = 1;
            rep(j , 0 , i - 1) {
                if(nums[i] > nums[j]) {
                    lis[i] = max(lis[i] , 1 + lis[j]);
                }
                maxi = max(maxi , lis[i]);
            }
        }
        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
