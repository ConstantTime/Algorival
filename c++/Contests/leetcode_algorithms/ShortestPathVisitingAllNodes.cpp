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

vector < int > a[N];
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        int dist[1 << n][n];
        int x = 1 << n;
        rep(i , 0 , x - 1) rep(j , 0 , n - 1) dist[i][j] = n * n;
        rep(i , 0 , n - 1) {
            dist[1 << i][i] = 0;
        }

        rep(cover , 0 , x - 1) {
            bool repeat = true;
            while(repeat) {
                repeat = false;
                rep(head , 0 , n - 1) {
                    int d = dist[cover][head];
                    for(int next : g[head]) {

                    } 
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
