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
    int kInversePairs(int n, int k) {
        if(k > (n * (n - 1)) / 2 || k < 0)
            return 0;
        if(k == 0 || k == (n * (n - 1)) / 2)
            return 1;
        ll dp[n + 1][k + 1];
        rep(i , 1 , n) {
            rep(j , 1 , k) dp[i][j] = 0;
        }
        
        if(n == 1) return 0;
        dp[2][0] = 1;
        dp[2][1] = 1;

        rep(i , 3 , n) {
            dp[i][0] = 1;
            rep(j , 1 , min((ll)k , (i * (i - 1)) / 2)) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                if(j >= i) {
                    dp[i][j] -= dp[i - 1][j - i];
                }
                dp[i][j] %= mod;
                if(dp[i][j] < 0) dp[i][j] += mod;
            }
        }

        return dp[n][k];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
