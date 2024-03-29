#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int dp[123456][3];
    int minCost(vector<vector<int>>& a) {
        int n = a.size();
        if(n == 0) return 0;
        int m = a[0].size();
        rep(i , 0 , n + 1) {
            rep(j , 0 , 2) dp[i][j] = 0;
        }

        rep(i , 0 , 2) {
            dp[0][i] = a[0][i];
        }

        rep(i , 1 , n - 1) {
            rep(j , 0 , 2) {
                dp[i][j] = a[i][j];
                int res = INT_MAX;
                rep(k , 0 , 2) {
                    if(j == k) continue;
                    res = min(res , dp[i - 1][k]);
                }
                dp[i][j] += res;
            }
        }

        return min(dp[n - 1][0] , min(dp[n - 1][1] , dp[n - 1][2]));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
        
    cin >> a;

    cout << longestPalindrome(a) << endl;

    return 0;
}
