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

int n , m , x;
int a[N];
int dp[123][12345];
int w[N];
int c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int t;
    cin >> t;

    while(t--) {
        
        cin >> n >> m >> x;

        rep(i , 1 , n) cin >> w[i];
        rep(i , 1 , n) cin >> c[i];

        vector < int > a[m + 1];
        rep(i , 1 , n) {
            a[c[i]].push_back(i);
        }

        rep(i , 1 , m) {
            rep(k , 1 , x) {
                dp[i][k] = 0;
            }
        }

        dp[0][0] = 1;

        rep(i , 1 , m) {
            for(auto j : a[i]) {
                rep(k , 1 , x) {
                    if(w[j] <= k) {
                        dp[i][k] = max(dp[i][k] , dp[i - 1][k - w[j]]);
                    }      
                }
            }
        }

        int ans = -1;
        rep(i , 1 , x) {
            if(dp[m][i] == 1)
                ans = i;
        }

        if(ans == -1) {
            cout << ans << endl;
        }
        else {
            cout << x - ans << endl;
        }
    }
    return 0;
}
