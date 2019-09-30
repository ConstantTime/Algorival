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
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector < int > ans;
        int cnt = 0;
        for(auto j : nums) {
            if(j != 0) {
                ans.push_back(j);
            }
            else cnt++;
        }      
        while(ans.size() != nums.size()) {
            ans.push_back(0);
        }
        nums = ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
