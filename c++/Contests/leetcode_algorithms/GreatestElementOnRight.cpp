#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 1534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;
int n;
int a[N];
int r[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n;

    rep(i , 1 , n) cin >> a[i];

    r[n] = a[n];
    per(i , n - 1 , 1) {
        r[i] = max(a[i] , r[i + 1]);
    }

    rep(i , 1 , n) {
        if(i == n) {
            cout << -1 << endl;
            continue;
        }
        cout << r[i + 1] << " ";
    }
    return 0;
}
