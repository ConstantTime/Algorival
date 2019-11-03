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

class Solution {
public:
    int rob(vector<int>& a , int num) {
        int n = a.size();
        if(n == 0) return 0;
        int dp[n];
        fill(dp , dp + n , 0);
        dp[0] = a[0];
        if(n == 1) return dp[0];
        dp[1] = max(dp[0] , a[1]);
        for(int i = 2 ; i < n ; i++) {
            int x = dp[i - 2] + a[i];
            int y = dp[i - 1];
            if(x < num && )
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