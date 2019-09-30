#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153457;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set < vector < int > > ans;
        map < int , vector < pair < int , int > > > a;
        rep(i , 0 , n - 1) {
            rep(j , i + 1 , n - 1) {
                a[nums[i] + nums[j]].push_back({i , j});
            }
        }

        rep(i , 0 , n - 1) {
            rep(j , i + 1 , n - 1) {
                int cur = target - nums[i] - nums[j];
                if(a.find(cur) != a.end()) {
                    for(auto k : a[cur]) {
                        if(k.first != i && k.first != j &&
                            k.second != i && k.second != j) {
                            vector < int > res;
                            res.push_back(nums[i]);
                            res.push_back(nums[j]);
                            res.push_back(nums[k.first]);
                            res.push_back(nums[k.second]);
                            sort(res.begin() , res.end());
                            ans.insert(res);
                        }
                    }
                }
            }
        }

        vector < vector < int > > check;

        for(auto j : ans) {
            check.push_back(j);
        }

        return check;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    Solution s;

    int k;
    cin >> k;
    cout << s.smallestRepunitDivByK(k) << endl;
    return 0;
}
