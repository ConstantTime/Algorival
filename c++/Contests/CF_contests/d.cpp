#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 353456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

ll power(ll a , ll b) {
    if(b == 0) return 1LL;
    ll d = power(a , b / 2);
    d *= d;
    d %= mod;

    if(b % 2 != 0) d *= a;

    d %= mod;

    return d;
}

ll inverse_mod(ll a) {
    return power(a , mod - 2);
}
vector < ll > a[N];
int color[N];

ll has(vector < ll > a) {
	ll ans = 0;
	ll index = 1;
	for(auto j : a) {
		ans += j * power(31 , index);
		ans %= mod;
		index++;
	}
	return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n , m;
    cin >> n >> m;

    rep(i , 1 , m) {
    	int x , y;
    	cin >> x >> y;
    	a[x].push_back(y);
    	a[y].push_back(x);
    }

    map < ll , vector < ll > > ans;
    rep(i , 1 , n) {
    	if(a[i].size() == 0) {
    		cout << -1 << endl;
    		return 0;
    	}
    	sort(a[i].begin() , a[i].end());
    	ans[has(a[i])].push_back(i);
    }

    if(ans.size() != 3) {
    	cout << -1 << endl;
    	return 0;
    }

    int index = 1;

    for(auto j : ans) {
    	for(auto k : j.second) {
    		color[k] = index;
    	}
    	index++;
    }

    rep(i , 1 , n) cout << color[i] << " ";
    cout << endl;

    return 0;
}
