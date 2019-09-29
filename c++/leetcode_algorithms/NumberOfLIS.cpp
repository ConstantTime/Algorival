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
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int lis[n];
        fill(lis , lis + n , 0);
        int cnt[n];
        fill(cnt , cnt + n , 0);
        rep(i , 0 , n - 1) {
            lis[i] = 1;
            cnt[i] = 1;
            rep(j , 0 , i - 1) {
                if(nums[j] < nums[i]) {
                    if(lis[i] == 1 + lis[j]) {
                        cnt[i] += cnt[j];
                    }
                    if(lis[i] < 1 + lis[j]) {
                        lis[i] = 1 + lis[j];
                        cnt[i] = cnt[j];
                    }
                }
            }
        }
        int max_len = 0;
        int res = 0;
        rep(i , 0 , n - 1) {
            if(max_len < lis[i]) {
                max_len = lis[i];
                res = cnt[i];
            }
            else if(max_len == lis[i]) res += cnt[i];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
