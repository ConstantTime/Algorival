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

int m , n;
bool comp(vector < int > a , vector < int > b) {
    return abs(a[0] - m) + abs(a[1] - n) < abs(b[0] - m) + abs(b[1] - n);
}
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector < vector < int > > ans;
        m = r0;
        n = c0;
        rep(i , 0 , R - 1) {
            rep(j , 0 , C - 1) {
                vector < int > res{i , j};
                ans.push_back(res);
            }
        }        
        sort(ans.begin(), ans.end(), comp);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
