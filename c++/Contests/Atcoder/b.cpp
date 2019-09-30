#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n , k;
    cin >> n >> k;

    rep(i , 1 , n) cin >> a[i];
    int cnt = 0;

    rep(i , 1 , n) {
        if(a[i] >= k) cnt++;
    }

    cout << cnt << endl;
    return 0;
}
