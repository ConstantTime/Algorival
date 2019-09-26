#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int a[N];

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n = matrix.size();

      if(n == 0) {
        return false;
      }      

      int m = matrix[0].size();

      rep(i , 0 , n - 1) {
        if(matrix[i].size() == 0) continue;
        if(matrix[i].size() == 1) {
          if(target == matrix[i][0]) {
            return true;
          }
          else{
            continue;
          }
        }
        if(matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target) {
          int x = binary_search(matrix[i].begin(), matrix[i].end()
            , target);

          if(x == 0) continue;
          return true;
        }
        else {
          continue;
        }
      }

      return false;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
