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

int n;
int parent[N];
vector < int > v[N];
int a[N];
int segtree[N];
bool lazy[N];
int tin[N];
int tout[N];
int rev[N];
int timer;
void dfs(int node){
    tin[node] = ++timer;
    rev[timer] = node;
    for(int next : v[node]){
        dfs(next);
    }
    tout[node] = timer;
}
int combine(int &a, int &b) {
    return a + b;
}
void build(int l , int r , int node){
    lazy[node] = 0;
    if(l == r){
        segtree[node] = a[rev[l]];
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
    }
}
inline void push(int l , int r , int node){
    if(lazy[node]){
        segtree[node] += (r - l + 1) * segtree[node];
        if(l != r){
            lazy[node + node] += lazy[node];
            lazy[node + node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update(int l , int r , int node , int ql , int x){
    // push(l , r , node);
    // if(l > qr || r < ql){
    //     return;
    // }
    // if(l >= ql && r <= qr){
    //     lazy[node] += (r - l + 1) * x;
    //     push(l , r , node);
    //     return;
    // }
    if(l == r) {
        segtree[node] += x;
        return ;
    }
    int mid = l + r >> 1;
    if(x <= mid)
        update(l , mid , node + node , ql , x);
    else
        update(mid + 1 , r , node + node + 1 , ql , x);
    segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
}
void update(int ql , int val){
    update(1 , n , 1 , ql , val);
}
int query(int l , int r , int node , int ql , int qr){
    //push(l , r , node);
    if(l > qr || r < ql){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    int a = query(l , mid , node + node , ql , qr);
    int b = query(mid + 1 , r , node + node + 1 , ql , qr);
    return combine(a , b);
}
int query(int ql , int qr){
    return query(1 , n , 1 , ql , qr);
}

int ant[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n;

    rep(i , 1 , n) cin >> a[i];

    rep(i , 1 , n - 1) {
        int x , y;
        cin >> x >> y;
        v[x].push_back(y);
        parent[y] = x;
    }

    dfs(1);

//  PRINT OPEN ******************************************
    rep(i , 1 , n) cout << tin[i] << " " ;
    cout << endl;
    rep(i , 1 , n) {
        cout << tout[i] << " ";
    }
    cout << endl;
    rep(i , 1 , timer) {
        cout << rev[i] << " " ; 
        ant[rev[i]] = i;
    }
    cout << endl;
//  PRINT CLOSE *****************************************

    build(1 , n , 1);
    int q;
    cin >> q;
    rep(i , 1 , q) {
        int t;
        cin >> t;

        if(t == 1) {
            int x , y;
            cin >> x >> y;
            update(ant[x] , y);
            continue;
        }
        int x ;
        cin >> x;

        cout << query(tin[x] , tout[x]) << endl;
    }
    return 0;
}
