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
    int profitableSchemes(int G, int P, vector<int>& a
        , vector<int>& profit) {
        
        int dp[P + 1][G + 1];
        rep(i , 0 , P) {
            rep(j , 0 , G) dp[i][j] = 0;
        }

        dp[0][0] = 1;
        rep(k , 0 , a.size() - 1) {
            int g = a[k];
            int p = profit[k];
            per(i , P , 0) {
                per(i , G - g , 0) {
                    dp[min(i + p , (ll)P)][j + g] += dp[i][j];
                    dp[min(i + p , (ll)P)][j + g] %= mod;
                }
            }
        }
        int res = 0;
        for(auto j : dp[P]) res = (res + j) % mod;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
