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
    int minCut(string s) {
        int n = s.length();
        int p[n][n];
        int dp[n];
        rep(i , 0 , n - 1) {
            fill(p[i] , p[i] + n ,  0);
        }
        fill(dp , dp + n , 0);
        rep(i , 0 , n - 1) {
            p[i][i] = 1;
        }
        rep(l , 2 , n) {
            rep(i , 0 , n - l) {
                int j = i + l - 1;
                if(l == 2) {
                    p[i][j] = (s[i] == s[j]);
                }
                else {
                    p[i][j] = (s[i] == s[j]) & p[i + 1][j - 1];
                }
            }
        }
        rep(i , 0 , n - 1) {
            if(p[0][i] == 1) {
                dp[i] = 0;
            }
            else {
                dp[i] = INT_MAX;
                rep(j , 0 , i - 1) {
                    if(p[j + 1][i] == 1) {
                        dp[i] = min(dp[i] , 1 + dp[j]);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
