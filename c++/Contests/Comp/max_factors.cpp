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

int a[N];
int res[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int t;
    cin >> t;

    while(t--) {
      int n;
      cin >> n;

      rep(i , 1 , n) cin >> a[i];

      unordered_map < int , vector < int > > check;

      rep(i , 1 , n) check[a[i]].push_back(i);

      fill(res + 1 , res + n + 1 ,  0);

      rep(i , 1 , n) {
        unordered_set < int > ans;
        rep(j , 1 , sqrt(a[i])) {
          
        }
      }

      int maxi = -1;

      rep(i , 1 , n) {
        maxi = max(maxi , res[i]);
      }

      cout << maxi << endl;
    }    
    return 0;
}
