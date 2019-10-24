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
    int minimumDeleteSum(string a , string b) {
        int n = a.length();
        int m = b.length();
        int dp[n + 1][m + 1];
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= m ; j++) {
                dp[i][j] = 0;
            }
        }
        per(i , n - 1 , 0) {
            dp[i][m] = dp[i + 1][m] + a[i];
        }
        per(i , m - 1 , 0) {
            dp[n][i] = dp[n][i + 1] + b[i];
        }
        per(i , n - 1 , 0) {
            per(j , m - 1 , 0) {
                if(a[i] == b[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = min(dp[i + 1][j] + a[i],
                        dp[i][j + 1] + b[j]);
                }
            }
        }
        return dp[0][0];
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
