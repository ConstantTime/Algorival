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

int n;
vector < int > a[N];

ll dp[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    int k;
    cin >> n >> k;

    rep(i , 1 , n) {
        int x , y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    rep(i , 1 , n) {
        rep(j , 1 , k) dp[i][j] = -1;
    }

    rep(i , 1 , n) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    rep(i , 1 , n) {
        rep(j , 2 , k) {
            dp[i][j] = 0;
            ll form = j - 1;
            rep(p , 0 , a[i].size() - 1) {
                
            }
        }
    }

    rep(i , 1 , n) {
        sum += dp[i][k];
        sum %= mod;
    }

    cout << sum << endl;

    return 0;
}
