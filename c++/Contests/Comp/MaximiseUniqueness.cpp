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

int n;
int ans = INT_MAX;

int U(string a) {
    unordered_map < int , int > ans;
    for(auto j : a) ans[j]++;
    return ans.size();
}

void doit(string a , string b , int l , int r) {
    if(l == r || l == n || r == n) {
        if(max(U(a) , U(b)) < ans) {
            ans = max(U(a) , U(b));
           // cout << a << " " << b <<  " " << ans << endl;
        }
        return ;
    }
    rep(i , l , r) {
        swap(a[i] , b[i]);
        doit(a , b , l + 1 , r);
        doit(a , b , l , r + 1);
        doit(a , b , l + 1 , r + 1);
        swap(a[i] , b[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        string a, b;
        cin >> a >> b;
        ans = max(U(a) , U(b));
        doit(a , b , 0 , n - 1);
        cout << ans << endl;
    }
    return 0;
}
