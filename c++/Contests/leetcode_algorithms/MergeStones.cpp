#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 1534567;
const long long mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int dp[123][123];
    int mergeStones(vector<int>& a, int k) {
        int n = a.size();
        if((n - 1) % (k - 1)) return -1;
        vector < int > pre(n + 1, 0);
        rep(i , 1 , n) {
            pre[i] = pre[i - 1] + a[i - 1];
        }

        rep(m , k , n) {
            rep(i , 0 , n - m) {
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                rep(mid , i , j - 1) {
                    dp[i][j] = min(dp[i][j] , 
                        dp[i][mid] + dp[mid + 1][j]);
                    mid += k - 2;
                }

                if((j - i) % (k - 1) == 0) {
                    dp[i][j] += pre[j + 1] - pre[i];
                }
            }
        }

        return dp[0][n - 1];

    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
