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

    ll a , b;
    cin >> a >> b;

    map< ll , ll > A = primeFactors(a);
    map< ll , ll > B = primeFactors(b);

    int cnt = 0;

    for(auto j : A) {
    	if(B.find(j.first) != B.end()) cnt++;
    }

    cout << cnt + 1 << endl;
    return 0;
}
