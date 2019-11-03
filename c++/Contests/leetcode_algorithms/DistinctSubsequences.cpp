#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        map < char , int > a;
        ll dp[n + 1];
        fill(dp , dp + n + 1 , 0);

        dp[0] = 1;  
        rep(i ,0 , n - 1) {
            dp[i + 1] = dp[i] * 2;
            dp[i + 1] %= mod;
            if(a.find(s[i]) != a.end()) {
                dp[i + 1] -= dp[a[s[i]]];
            }
            dp[i + 1] += mod;
            dp[i + 1] %= mod;
            a[s[i]] = i;
        }

        dp[n]--;
        dp[n] += mod;
        dp[n] %= mod;
        return dp[n];
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}