#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 100005;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int n;
int a[N];
int b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    cin >> n;

    rep(i , 1 , n) cin >> a[i];
    rep(i , 1 , n) cin >> b[i];

    vector < pair < int , int > > c;
    rep(i , 1 , n) {
        c.emplace_back(a[i] , 1);
    }

    rep(i , 1 , n) {
        c.emplace_back(b[i] , -1);
    }

    sort(c.begin() , c.end());

    int ans = 0;
    int num = 0;

    for(auto j : c) {
        num += j.second;
        if(num > ans) {
            ans = num;
        }
    }

    cout << ans << endl;

    return 0;
}