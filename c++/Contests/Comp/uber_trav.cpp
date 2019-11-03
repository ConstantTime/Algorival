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
int g;
vector < int > a[N];
pair < int , int > ans[N];
int ind[N];
int par[N];

int find(int x) {
    while(x != par[x]) {
        x = par[x];
    }
    return x;
}

int Union(int x , int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(ind[x] >= ind[y]) {
            par[y] = x;
            ind[x] += (ind[x] == ind[y]);
        }
        else {
            par[x] = y;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n >> g;
    int q;
    cin >> q;

    rep(i , 1 , n) par[i] = i;
    rep(i , 1 , n) ind[i] = 0;

    rep(i , 1 , q) {
        cin >> ans[i].first;
    }
    cin >> q;
    rep(i , 1 , q) {
        cin >> ans[i].second;
    }

    vector < int > res;

    rep(i , g + 1 , n) {
        int f = 2;
        while(i * f <= n) {
            Union(i , i * f);
            f++;
        }
    }

    rep(i , 1 , q) {
        if(g == 0) {
            res.push_back(1);
            continue;
        }
        if(g >= n) {
            res.push_back(0);
            continue;
        }
        res.push_back(find(ans[i].first) == find(ans[i].second));
    }

    for(auto j : res) cout << j << " ";
    cout << endl;

    return 0;
}
