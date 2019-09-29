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
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        int dp[n + 1];
        fill(dp , dp + n + 1 ,  0);
        rep(i , 1 , n) {
            int m = 0;
            for(int j = i - 1  ; j >= 0 && j >= i - K ; j--) {
               // if(j < i - K) break;
                m = max(m , A[j]);
                dp[i] = max(dp[i] , dp[j] + m * (int) (i - j));
            }
        }   
        return dp[n];   
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
