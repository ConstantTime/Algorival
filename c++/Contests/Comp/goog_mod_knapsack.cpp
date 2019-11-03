#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 100005;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int n;
int a[N];

int dp[N];

int solve(int maxi , int n) {
    if(n < 0) return 0;
    if(dp[n][maxi] != -1) return dp[n][maxi];
    int ans = 0;
    int nots = solve(maxi , n - 1);
    int sel =  mxi - a[n]  0 : 0 ? a[n] + solve(maxi , - a[n] , n - 2);
    int ans = max(nots , sel); 
    dp[n][maxi] = ans;
    return ans;
}
int number(int maxi) {
    fill(dp , dp + N , -1);
    int res = solve(maxi , n - 1);
    if(res < 0) return 0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}