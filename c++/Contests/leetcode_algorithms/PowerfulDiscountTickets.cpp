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
long long a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n , m;
    cin >> n >> m;

    rep(i , 1 , n) cin >> a[i];
    priority_queue < ll > ans;

    rep(i , 1 , n) {
        ans.push(a[i]);
    }

    ll sum = 0;
    ll total = 0;

    rep(i , 1 , n) {
        total += a[i];
    }
    while(m--) {
        ll x = ans.top();
        ans.pop();
        sum += x - x / 2;
        ans.push(x / 2);
    }

    cout << total - sum << endl;
    return 0;
}
