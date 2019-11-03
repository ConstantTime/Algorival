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

vector < int > a[N];
int b[N];
int c[N];

int dp[N][2];

void dfs(int s , int par) {
    int cc = b[s];
    int cnt1 = 0;
    int cnt2 = 0;
    for(auto j : a[s]) {
        if(j == par) continue;
        dfs(j , s);
        cnt1 += dp[j][0];
        cnt2 += dp[j][1];
    }
    int x = 1;
    dp[s][0] = min(cnt1 + cc , cnt2 + !cc + x);
    dp[s][1] = min(cnt2 + !cc , cnt1 + cc + x);
}

int p[N][32];

void dfs(int s , int p , int cnt) {
    level[s] = cnt;
    for(auto j : a[s]) {
        if(j == p) continue;
        dfs(j , s , cnt + 1);
    }
}
void preprocess() {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; (1 << j) < n ; j++) {
            p[i][j] = -1;
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        p[i][0] = par[i];
    }

    for(int j = 1 ; (1 << j) < n ; j++) {
        for(int i = 1 ; i <= n ; i++) {
            if(p[i][j - 1] != -1) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u , int v) {
    if(level[u] < level[v]) {
        swap(u , v);
    }
    int dist = level[u] - level[v];
    while(dist > 0) {
        int raise = log2(dist);
        u = p[u][raise];
        dist -= (1 << raise);
    }

    if(u == v) {
        return u;
    }

    for(int j = 16 ; j >= 0 ; j--) {
        if(p[u][j] != -1 && p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }
    }

    return par[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    cin >> n;

    rep(i , 1 , n - 1) {
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    rep(i , 1 , n) {
        cin >> b[i];
    }

    rep(i , 1 , n) cin >> c[i];
    rep(i , 1 , n) {
        b[i] = (b[i] ^ c[i]);
    }

    cout << endl;
    rep(i , 1 , n) {
        cout << b[i] << " ";
    }
    cout << endl;

    dfs(1 , 0);

    rep(i , 1 , n) {
        cout << i << " -> " << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << dp[1][0] << endl;

    return 0;
}