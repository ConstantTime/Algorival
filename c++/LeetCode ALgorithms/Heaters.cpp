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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();

        int m = heaters.size();

        int len = INT_MIN;

        vector < int > a(n , INT_MAX);

        rep(i , 0 , m - 1) {
            rep(j , 0 , n - 1) {
                a[j] = min(a[j] , abs(heaters[i] - houses[j]));
            }
        }

        rep(i , 0 , n - 1) {
            len = max(len , a[i]);
        }

        return len;      
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
