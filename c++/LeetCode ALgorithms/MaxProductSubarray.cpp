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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi = 1;
        int cur_maxi = 1;
        int cur_mini = 1;
        bool flag = false;

        rep(i , 0 , n - 1) {
            if(nums[i] > 0) {
                flag = true;
                cur_mini = min(1 , cur_mini * nums[i]);
                cur_maxi = max(1 , cur_maxi * nums[i]);
            }
            else if(nums[i] == 0) {
                cur_maxi = 1;
                cur_mini = 1;
            }
            else {
                int temp = cur_maxi;
                cur_maxi = max(cur_mini * nums[i] , 1);
                cur_mini = nums[i] * temp;
            }

            maxi = max(maxi , cur_maxi);
        }

        if(flag == false && maxi == 1) {
            rep(i , 0 , n - 1) {
                maxi = max(maxi , nums[i]);
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
