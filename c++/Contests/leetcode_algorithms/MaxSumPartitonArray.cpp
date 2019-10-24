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
int a[N];
int dp[1234][1234];

double DP(int n , int k) {
    if(dp[i][j] != -1) return dp[i][j];
    double sum = 0;
    per(i , n - 1 , 1) {
        sum += a[i];
        dp[n][k] = max(dp[n][k] , DP(i , k - 1) + 
            sum / (n - i));
    }
    return dp[n][k];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n;

    rep(i , 1 , n) cin >> a[i];

    double sum = 0;

    rep(i , 1 , n) {
        fill(dp[i] , dp[i] + k + 1 , -1);
    }

    rep(i , 1 , n) {
        sum += a[i];
        dp[i][1] = sum / (double)i;
    }

    cout << DP(n , k) << endl;

    return 0;
}
