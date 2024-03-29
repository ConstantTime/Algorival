#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int maximumProduct(vector<int>& a) {
      int n = a.size();
      sort(a.begin() , a.end());
      return max(a[n - 1] * a[n - 2] * a[n - 3] , 
        max(a[n - 1] * a[0] * a[1] , max(a[n - 1] * a[n - 2] * a[0]
                                         , max(a[n - 1] * a[n - 2] * a[0] , INT_MIN))));      
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
