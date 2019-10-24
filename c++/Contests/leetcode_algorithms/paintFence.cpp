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
    int shortestDistance(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        auto total = a;
        int delta [] = {0 , 1 , 0 , -1 , 0};
        int mini = 0;
        rep(i , 0 , n - 1) {
            rep(j , 0 , m - 1) {
                if(a[i][j] == 1) {
                    mini = -1;
                    queue < pair < int , int > > q;
                    q.push({i , j});
                }
            }
        }
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
