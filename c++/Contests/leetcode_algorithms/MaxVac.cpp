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
    int dp[123][123];
    int n , k;
    vector < vector < int > > a , b;
    
    int dfs(int i , int week) {
        if(week == k) return 0;
        if(dp[i][week] != INT_MIN) return dp[i][week];
        int maxi = 0;
        rep(j , 0 , n - 1) {
            if(a[i][j] == 1 || j == i) {
                maxi = max(maxi , b[j][week] + dfs(j , week + 1));
                cout << i << " " << j << " " << maxi << endl;
            }
        }

        dp[i][week] = maxi;
        return maxi;
    }
    int maxVacationDays(vector<vector<int>>& A, 
        vector<vector<int>>& days) {
        n = A.size();
        k = days[0].size();
        this -> a = A;
        b = days;
        rep(i , 0 , n) {
            rep(j , 0 , n) dp[i][j] = INT_MIN;
        }
        return dfs(0 , 0);
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
