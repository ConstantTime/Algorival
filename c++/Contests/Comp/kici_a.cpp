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

int n , m , q;
int a[N];
int p[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int t;
    cin >> t;

    rep(pp , 1 , t) {
        cin >> n >> m >> q;
        
        rep(i , 1 , N - 1) p[i] = 0;

        rep(i , 1 , m) {
            int x;
            cin >> x;
            p[x] = 1;
        }

        rep(i , 1 , q) cin >> a[i];

        int cnt = 0;

        rep(i , 1 , q) {
            for(int j = a[i] ; j <= n ; j += a[i]) {
                if(p[j] == 0) cnt++;
            }
        }


        cout << "Case #" << pp << ": " << cnt << endl;
    }

    
    return 0;
}
