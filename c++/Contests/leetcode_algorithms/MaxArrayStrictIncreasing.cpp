#include <bits/stdc++.h>
 
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 153456;
const long long mod = 1e18 + 7;
const long double eps = 1e-6;
const long double pi = 3.1415926535;

class Solution {
public:
    int dp[2001][2001];
    int dfs(vector < int > a1 , vector < int > a2 , int i , int j, int prev) {
        if(i >= a1.size()) return 1;
        j = upper_bound(a2.begin() + j , a2.end() , prev) - a2.begin();
        if(dp[i][j]) return dp[i][j];
        int A = j < a2.size() ? 1 + dfs(a1 , a2 , i + 1 , j , a2[j]) :
        a2.size() + 1;
        int B = a1[i] > prev ? dfs(a1 , a2 , i + 1 , j , a1[i]) :
        a2.size() + 1;
        return dp[i][j] = min(A , B);
    }
    int makeArrayIncreasing(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        sort(a2.begin(), a2.end());
        int res = dfs(a1 , a2 , 0 , 0 , INT_MIN);
        return res > a2.size() ? -1 : res - 1;
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
