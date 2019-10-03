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

set < int > a[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    string s = "";
    int n = 1e5;
    rep(i , 1 , n) {
    	s += 'a';
    }
    cout << s << endl;
    cout << n << endl;

    rep(i , 1 , n) {
    	cout << 1 << " " << n / 2 << " " << 'a' << endl;
    }
    return 0;
}
