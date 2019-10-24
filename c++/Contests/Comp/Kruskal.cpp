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

int n, m;
pair < int , pair < int , int > > a[N];
int id[N];

int root(int x) {
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void Union(int x , int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

ll kruskal() {
    ll ans = 0;
    rep(i , 1 , m) {
        int x = a[i].second.first;
        int y = a[i].second.second;
        ll cost = a[i].first;
        if(root(x) != root(y)) {
           // cout << x << " ff " << y << " cost -> " << cost << endl;
            ans += cost;
            Union(x , y);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n >> m;

    rep(i , 1 , n) id[i] = i;

    rep(i , 1 , m) {
        int u , v , t;
        cin >> u >> v >> t;
        if(t == 0) {
            a[i] = {0 , {u , v}};
        }
        else {
            int cost;
            cin >> cost;
            a[i] = {cost , {u , v}};
        }
    } 

    sort(a + 1 , a + m + 1);

    cout << kruskal() << endl;
    return 0;
}
