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
class Solution {
public:
    int scoreOfParentheses(string s) {
  		int n = s.length();      
  		stack < char > a;

  		int l = 0;
  		int cur = 0;

  		rep(i , 0 , n - 1) {
  			char j = s[i];
  			if(j ==  '(') {
  				a.push(j);
  			}
  			else {
  				a.pop();
  				if(l <= a.size()) {
  					l = a.size();
  					cur += power(2 , l);
  				}
  				else {
  					l = a.size();
  				}
  			}
  		}

  		return cur;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
