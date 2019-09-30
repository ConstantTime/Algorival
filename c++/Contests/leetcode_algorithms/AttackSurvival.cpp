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
long long a[N];

const long long LIM = 6e5 + 5;
long long seg[LIM];
long long lazy[LIM];
bool push[LIM];

long long combine(long long &a, long long &b) {
    return max(a, b);
}
void propagate(long long t, long long i, long long j) {
    if (push[t]) {
        seg[t] = seg[t] + lazy[t];
        if (i != j) {
            push[t*2] = true;
            push[t*2 + 1] = true;
            lazy[t*2] = lazy[t*2] + lazy[t];
            lazy[t*2 + 1] = lazy[t*2 + 1] + lazy[t];
        }
        push[t] = false;
        lazy[t] = 0;
    }
}
void build(long long t, long long i, long long j) {
    push[t] = false;
    lazy[t] = 0;
    if (i == j) {
        seg[t] = a[i];
        return ;
    }
    long long mid = (i + j) / 2;
    build(t*2, i, mid);
    build(t*2 + 1, mid + 1, j);
    seg[t] = combine(seg[2*t], seg[2*t+1]);
}
void update(long long t, long long i, long long j, long long l, long long r, long long x) {
    propagate(t, i, j);
    if (i > r || j < l) {
        return ;
    }
    if (l <= i && j <= r) {
        lazy[t] += x;
        push[t] = true;
        propagate(t, i, j);
        return ;
    }
    long long mid = (i + j) / 2;
    update(t*2, i, mid, l, r, x);
    update(t*2 + 1, mid + 1, j, l, r, x);
    seg[t] = combine(seg[2*t], seg[2*t+1]);
}
long long query(long long t, long long i, long long j, long long l, long long r) {
    propagate(t, i, j);
    if (i > r || j < l) {
        return 0;
    }
    if (l <= i && j <= r) {
        return seg[t];
    }
    long long mid = (i + j) / 2;
    if (l <= mid) {
        if (r <= mid) {
            return query(t*2, i, mid, l, r);
        }
        else {
            long long a = query(t*2, i, mid, l, r);
            long long b = query(t*2 + 1,  mid + 1, j, l, r);
            return combine(a, b);
        }
    }
    else {
        return query(t*2 + 1,  mid + 1, j, l, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n , k , q;
    cin >> n >> k >> q;

    rep(i , 1 , n) a[i] = k;

    build(1 , 1 , n);
    while(q--) {
        int x;
        cin >> x;
        update(1 , 1 , n , 1 , x - 1 , -1);
        update(1 , 1 , n , x + 1 , n , -1);
    }

    rep(i , 1 , n) {
        int x = query(1 , 1 , n , i , i);
        string s = "";
        if(x <= 0) {
            s = "No";
        }
        else {
            s = "Yes";
        }
        cout << s << endl;
    }
    return 0;
}
