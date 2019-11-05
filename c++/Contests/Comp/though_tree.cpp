#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 100005;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int c[N];
vector < int > a[N];
int par[N];
int n;
int dp[4][N];

void dfs(int s, int p) {
    bool flag = false;
    int fi = 0;
    int se = 0;
    int th = 0;
    int fo = 0;
    for(auto j : a[s]) {
        if(j == p) continue;
        dfs(j , s);
        flag = true;
        fi += dp[2][j];
        se += dp[0][j];
        th += dp[1][j];
        fo += max(dp[0][j] , dp[1][j]);
    }
    dp[0][s] = fi + c[s];
    dp[1][s] = se;
    dp[2][s] = th;
    dp[3][s] = fo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    cin >> n;

    int root = -1;

    rep(i , 1 , n) {
        cin >> par[i];
        a[par[i]].push_back(i);
        if(par[i] == 0) root = i;
    }

    rep(i , 1 , n) {
        cout << i << "-> ";
        for(auto j : a[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    rep(i , 1 , n) cin >> c[i];

    dfs(root , 0);

    cout << max(dp[0][root] , max(dp[1][root] , 
        max(dp[3][root] , dp[2][root]))) << endl;;

    return 0;
}