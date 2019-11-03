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

int a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int n;
    cin >> n;

    rep(i , 1 , n) cin >> a[i];
    int l = 1;
    int r = n;
    int ans = 0;
    while(l < r) {
        while(a[l] % 2 == 0 & l < r) l++;
        while(a[r] % 2 == 1 && l < r) r--;
        if(l < r) {
            swap(a[l] , a[r]);
            l++;
            ans++;
            r--;
        }
    }
    cout << ans << endl;

    return 0;
}
