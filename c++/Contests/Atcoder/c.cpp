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

    int n;
    cin >> n;
    rep(i , 1 , n) {
    	cin >> a[i];
    }

    vector < pair < int , int > > res;

    rep(i , 1 , n) {
    	res.push_back({a[i] , i});
    }

    sort(res.begin() , res.end());

    rep(i , 1 , n) {
    	cout << res[i - 1].second << " ";
    }
    cout << endl;
    return 0;
}
