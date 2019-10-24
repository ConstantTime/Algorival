#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 553456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int n;
int dp[1234][1234];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    string a;
    cin >> a;
    string b = a;
    reverse(b.begin() , b.end());
    string c = a + "$" + b;
    int n = c.length();

    int z[n];
    fill(z , z + n , 0);
    int l = 0;
    int r = 0;

    rep(i , 1 , n - 1) {
        if(i > r) {
            l = r = i;
            while(r < n && c[r - l] == c[r]) {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else {
            int k = i - l;
            if(z[k] < r - i + 1) {
                z[i] = z[k];
            }
            else {
                l = i;
                while(r < n && c[r - l] == c[r]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }

    int i = n - 1;

    int ans = 0;

    while(c[i] != '$') {
        if(z[i] == n - i) {
            ans = z[i];
        }
        i--;
    }

    cout << ans << endl;

    return 0;
}
