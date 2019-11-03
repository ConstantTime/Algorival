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
    int shortestWay(string s, string t) {
        int m = t.length();
        s += s;
        int n = s.length();
        int dp[n + 1][m + 1];

        rep(i , 0 , n) {
            rep(j , 0 , m) dp[i][j] = 0;
        }

        rep(i , 1 , n) {
            rep(j , 1 , m) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
                }
            }
        }

        rep(i , 1 , n) {
            rep(j , 1 , m) cout << dp[i][j] << " ";
            cout << endl;
        }

        return dp[n][m];
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
