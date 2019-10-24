int n;
int parent[N];
vector < int > v[N];
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

int arr[N];
int segtree[N];
bool lazy[N];
int combine(int &a, int &b) {
    return a + b;
}
void build(int l , int r , int node){
    lazy[node] = 0;
    if(l == r){
        segtree[node] = arr[rev[l]];
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
        segtree[node] = r - l + 1 - segtree[node];
        if(l != r){
            lazy[node + node] ^= 1;
            lazy[node + node + 1] ^= 1;
        }
        lazy[node] = 0;
    }
}
void update(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        lazy[node] ^= 1;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr);
    update(mid + 1 , r , node + node + 1 , ql , qr);
    segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
}
void update(int ql , int qr){
    update(1 , n , 1 , ql , qr);
}
int query(int l , int r , int node , int ql , int qr){
    push(l , r , node);
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