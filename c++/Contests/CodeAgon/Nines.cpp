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

int roundd(int n) {
	int last = n % 10;
	int temp = n;
	if(last < 5) {
		n -= last;
		n--;
	}
	else {
		int add = 10 - last;
		n += add;
		n--;
	}

	if(n > temp) {
		n -= 10;
	}

	return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int t;
    cin >> t;
    while(t--) {
    	ll n;
    	cin >> n;

    	ll sum = 1;
    	bool flag = false;

    	int local = n;
    	while(1) {
    		int temp = roundd(n);
    		if(temp < 0) break;
    		if((local - temp) % 9 == 0) {
    			sum = 1 + (local - temp) / 9;
    			flag = true;
    			break;
    		}

    		n = temp - 1;
    		if(n < 0) break;

    		if((local - temp) / 9 > 10) break;
    	}
    	if(flag == false) {
    		cout << -1 << endl;
    		continue;
    	}

    	cout << sum << endl;
    }
    
    return 0;
}
