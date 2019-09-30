#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
ll mod = 5e18;
const ll MOD = 1000000000 + 7;
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

map < ll , ll > primeFactors(ll n)  {  
	map < ll , ll > ans;
    while (n % 2 == 0) {
    	ans[2]++;
    	n = n / 2;
    }  
    for (ll i = 3; i <= (long long)sqrt(n) + 1 ; i = i + 2) {  
        while (n % i == 0) { 
            ans[i]++;
            n = n / i;
        }  
    }  
    if(n >= 2)
	    ans[n]++;

    return ans;
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    ll x , n;
    cin >> x >> n;
    mod += 7;
   	ll ans = 1;

    map < ll , ll > res = primeFactors(x);

    for(auto j : res) {
    	ll num = j.first;
    	ll cnt = 0;
    	ll count = 0;
    	ll number = n;
    	mod = 2e18;
    	mod += 7;
    	while(1) {
    		if(number / num == 0) {
    			break;
    		}
    		number = number / num;
    		cnt++;
    	}
    	rep(jj , 1 , cnt) {
    		count += (n / power(num , jj));
    	}
    	//cout << num << " " << cnt << " " << count << endl;
    	mod = 1e9 + 7;
    	ans *= power(num , count);
    	ans %= mod;
    	//cout << power(num , count) % mod << endl;
    	if(ans < 0) ans += mod;
    }

    cout << ans << endl;
    return 0;
}
