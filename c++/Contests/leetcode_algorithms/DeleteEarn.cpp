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

class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        int n = a.size();
        int maxi = -1;
        for(auto j : a) maxi = max(maxi , j);
        int dp[maxi + 5];
        n = maxi + 5;
        rep(i , 0 , n - 1) dp[i] = 0;
        for(auto j : a) dp[j]++;
        sort(a.begin() , a.end());
        int vis[n];
        fill(vis , vis + n , 0);
        rep(i , 0 , n - 1) {
            int j = i;
            if(vis[j] == 1) continue;
            vis[j] = 1;
            dp[j] *= j;
            int k = j - 2 >= 0 ? dp[j - 2] : 0;
            int m = j - 3 >= 0 ? dp[j - 3] : 0;
            dp[j] += max(k , m);
        }
        maxi = -1;
        rep(i , 0 , n - 1) {
            cout << dp[i] << " ";
        }
        cout << endl;
        rep(i , 0 , n - 1) maxi = max(maxi , dp[i]);
        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
