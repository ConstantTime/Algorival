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

int n, m;
int a[3234][3234];
int dp[3234][3234];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n >> m;

    rep(i , 1 , n) rep(j , 1 , m) cin >> a[i][j];

    rep(i , 1 , n) {
        dp[i][1] = dp[i - 1][1] + a[i][1];
    }

    rep(j , 1 , m) {
        dp[1][j] = dp[1][j - 1] + a[1][j];
    }

    int q;
    cin >> q;

    rep(i , 1 , q) {
        int x , y , k;
        cin >> x >> y >> k;


    }
    return 0;
}
