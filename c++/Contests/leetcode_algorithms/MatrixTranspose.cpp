#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size();
        if(n == 0) return A;
        int m = A[0].size();
        vector < vector < int > > ans;
        rep(j , 0 , m - 1) {
          vector < int > res;
          rep(i , 0 , n - 1) {
            res.push_back(A[i][j]);
          }
          ans.push_back(res);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
e