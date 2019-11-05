#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 300005;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int n;
int a[N];
int m;
int maxi = -1;
int ans1 = 0;
int ans2 = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    cin >> n;
    rep(i , 1 , n) cin >> a[i];

    cin >> m;
    vector < int > b(m);
    rep(i , 1 , m) cin >> b[i - 1];

    sort(a + 1 , a + n + 1);
    sort(b.begin(), b.end());
    ans1 = 2 * n;
    ans2 = 2 * m;
    maxi = ans1 - ans2;

    rep(i , 1 , n) {
        int t = lower_bound(b.begin() , b.end() , a[i]) - (b.begin());
        ll t1 = (i - 1) * 2 + 3 * (n - i + 1);
        ll t2 = t * 2 + 3 * (m - t);
        if(t1 - t2 > maxi) {
            maxi = t1 - t2;
            ans1 = t1;
            ans2 = t2;
        }
        else if(t1 - t2 == maxi) {
            if(t1 > ans1) {
                ans1 = t1;
                ans2 = t2;
            }
        }
    }

    cout << ans1 << ":" << ans2 << endl;
    
    return 0;
}