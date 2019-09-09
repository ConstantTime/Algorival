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
    int search(vector<int>& nums, int target) {
        int x = binary_search(nums.begin() , nums.end() , target);
        if(x == -1) return x;

        int l = 0;
        int n = nums.size() - 1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }   
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
