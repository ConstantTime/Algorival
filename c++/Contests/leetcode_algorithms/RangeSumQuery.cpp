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

class NumMatrix {
public:
    vector < vector < int > > a;
    int n , m;
    NumMatrix(vector<vector<int>>& matrix) {
        a = matrix;
        n = a.size();
        if(n == 0) m = -1;
        else m = a[0].size();
        rep(i , 1 , m - 1) {
            a[0][i] += a[0][i - 1];
        }
        rep(i , 1 , n - 1) {
            a[i][0] += a[i - 1][0];
        }
        rep(i , 1 , n - 1) {
            rep(j , 1 , m - 1) {
                a[i][j] += (a[i - 1][j] + a[i][j - 1]
                    - a[i - 1][j - 1]);
            }
        }
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        
        int one = a[x2][y2];
        int two = x1 - 1 >= 0 ? a[x1 - 1][y2] : 0;
        int three = y1 - 1 >= 0 ? a[x2][y1 - 1] : 0;
        int four = x1 - 1 >= 0 && y1 - 1 >= 0 ? a[x1 - 1][y1 - 1] : 0;
        return one - two - three + four;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(x1,y1,x2,y2);
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
