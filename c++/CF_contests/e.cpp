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

map < ll , ll > a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int q;
    cin >> q;

    rep(i , 1 , 100000LL) {
    	a[(i * (i + 1)) / 2] = i;
    }

    while(q--) {
    	int k;
    	cin >> k;

    	
    }
    
    return 0;
}
