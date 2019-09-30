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

string ss = "Case #";
void print(ll pp , ll ans) {
	cout << ss << "" << pp << ": " << ans << endl;
}

bool comp(vector < int > a , vector < int > b) {

}

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

ll h[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int t;
    cin >> t;

    rep(pp , 1 , t) {
    	int n , s;
    	cin >> n >> s;

    	vector < int > a[n + 1];

    	rep(i , 1 , n) {
    		int sz;
    		cin >> sz;
    		rep(j , 1 , sz) {
    			int x;
    			cin >> x;
    			a[i].push_back(x);
    		}
    	}

    	rep(i , 1 , n) {
    		h[i] = has(a[i]);
    	}

    	
    }
    return 0;
}
