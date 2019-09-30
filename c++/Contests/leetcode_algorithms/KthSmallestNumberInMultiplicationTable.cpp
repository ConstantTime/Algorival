#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 0;
        int r = m * n;

        while(l < r) {
          int cnt = 0;
          int mid = l + (r - l) / 2;
          rep(i , 1 , m) {
            cnt += min((int)mid / (int)i , n);
          }

        //  cout << l << ' ' << r << " " << cnt << endl;

          if(cnt < k) {
            l = mid + 1;
          }
          else r = mid;
        }

        return l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
