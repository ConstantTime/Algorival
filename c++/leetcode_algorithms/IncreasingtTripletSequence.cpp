#include <bits/stdc++.h>
 
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 153456;
const long long mod = 1e18 + 7;
const long double eps = 1e-6;
const long double pi = 3.1415926535;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int a , b;
        a = INT_MAX;
        b = INT_MAX;
        rep(i , 0 , n - 1) {
            if(nums[i] <= a) {
                a = nums[i];
            }
            else if(nums[i] <= b) {
                b = nums[i];
            }
            else {
                return true;
            }
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
    