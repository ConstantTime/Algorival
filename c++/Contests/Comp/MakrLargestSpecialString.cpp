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

string s;

void fun(int start , int end) {
  int cnt = 0;
  vector < string > res;
  rep(i , start , end) {
    if(s[i] == '1') cnt++;
    else cnt--;
    if(cnt == 0) {
      
    }
  }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> s;

    fun(0 , n - 1);

    cout << s << endl;
    return 0;
}
