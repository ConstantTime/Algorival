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

int n;
int m;
int dp[N];
vector < int > a[N];

void dfs(int s , int par) {
    int sz = 0;
    int sum = 0;
    for(auto j : a[s]) {
        if(j != par) {
            sz++;
            dfs(j);
            sum += dp[j];
        }
    }
    if(sz == 0) {
        dp[s] = 1;
        return ;
    }
    int inc = 1;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    cin >> n;

    rep(i , 1 , n - 1) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1 , 0);
    return 0;
}
