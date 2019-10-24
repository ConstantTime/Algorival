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

long long seg[4 * N];
long long combine(long long &a, long long &b) {
    return a + b;
}
void update(long long t, long long i, long long j) {
    if (i == j) {
        seg[t] = 0;
        return ;
    }
    long long mid = (i + j) / 2;
    update(t * 2, i, mid);
    update(t * 2 + 1, mid + 1, j);
    seg[t] = combine(seg[2*t], seg[2*t+1]);
}
void update(long long t, long long i, long long j, long long x, long long y) {
    if (i > y || j < x) {
        return ;
    }
    if (i == j) {
        seg[t] = y;
        return ;
    }
    long long mid = (i + j) / 2;
    update(t * 2, i, mid, x, y);
    update(t * 2 + 1, mid + 1, j, x, y);
    seg[t] = combine(seg[2*t], seg[2*t+1]);
}
long long query(long long t, long long i, long long j, long long l, long long r) {
    if (l <=i && j <= r) {
        return seg[t];
    }
    long long mid = (i + j) / 2;
    if (l <= mid) {
        if (r <= mid) {
            return query(t * 2, i, mid, l, r);
        }
        else {
            long long a = query(t * 2, i, mid, l, r);
            long long b = query(t * 2 + 1,  mid + 1, j, l, r);
            return combine(a, b);
        }
    }
    else {
        return query(t * 2 + 1,  mid + 1, j, l, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int n;
    cin >> n;
    bool update = false;

    stack < pair < int , int > > s;
    int time = 0;
    // segment tree update for the timed range
    rep(i , 1 , n) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            s.push({time , x});
            time++;
        }
        else if(t == 2) {
            if(s.empty()) {
                cout << "Stack is empty" << endl;
                continue;
            }
            //pop;
            pair < int , int > ans = s.top();
            time = ans.first;
            cout << ans.second << endl;
        }
        else {
            int e , k;
            cin >> e >> k;
            
        }
    }
    return 0;
}
