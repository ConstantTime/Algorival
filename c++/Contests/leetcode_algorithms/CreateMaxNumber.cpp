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

int a[N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    cin >> n;

    rep(i , 1 , n) cin >> a[i];
    
    int res = 0;

    rep(i , 1 , n) {
        if(a[i] == 1) {
            if(res == 0 || a[i - 1] == 1) res++;
            else res += 2;
        }
    }   

    cout << res << endl;
    return 0;
}
