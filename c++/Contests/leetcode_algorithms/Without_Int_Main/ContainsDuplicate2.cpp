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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map < int , vector < int > > a;
        rep(i , 0 , n - 1) {
            a[nums[i]].push_back(i);
        }
        bool flag = false;
        for(auto j : a) {
            if(j.second.size() <= 1) continue;
            rep(i , 0 , j.second.size() - 2) {
                if(j.second[i + 1] - j.second[i] <= k) return true;
            }
        }
        return flag;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(12);
   
    return 0;
}
