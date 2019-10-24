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

int dp[N][3];
//0 for camera on the position
//1 for camera on the child
//2 for camera on the parent

int min(int a , int b , int c) {
    return min(a , min(b , c));
}

void dfs(int i , int par) {
	int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    int sz = 0;
    bool found = false;
    for(auto child : a[i]) {
        if(child == par) continue;
        dfs(child , i);
        sz++; 
        res1 += min(dp[child][0] , dp[child][1] , dp[child][2]);
        if(dp[child][0] <= dp[child][1]) {
            found = true;
            res2 += dp[child][0];
        }
        else {
            res2 += dp[child][1];
        }
        res3 += min(dp[child][0] , dp[child][1]);
    }
    dp[i][0] = 1 + res1;
    dp[i][2] = res3;
    if(sz == 0) {
        dp[i][1] = 999999;
        return ;
    }
    if(found == true) {
        dp[i][1] = res2;
    }
    else {
        int mini = INT_MAX;
        int index = -1;
        for(auto child : a[i]) {
            if(child == par) continue;
            if(dp[child][1] - dp[child][0] < mini) {
                index = child;
            } 
        }
        res2 = 0;
        for(auto child : a[i]) {
            if(child == par) continue;
            if(child == index) {
                res2 += dp[child][0];
            }
            else {
                res2 += dp[child][1];
            }
        }
        dp[i][1] = res2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    int n;
    cin >> n;

    rep(i , 1 , n - 1) {
    	int x , y;
    	cin >> x >> y;

    	a[x].push_back(y);
    	a[y].push_back(x);
    }

    dfs(1 , 0);

    cout << min(dp[1][0] , dp[1][1]) << endl;
    return 0;
}
