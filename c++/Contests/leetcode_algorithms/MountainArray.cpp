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
    int findInMountainArray(int b, MountainArray &a) {
        int n = a.length();
        int index = -1;
        int L = 0;
        int R = n - 1;

        while(L < R) {
            int mid = (L + R) / 2;
            if(a.get(mid) < a.get(mid + 1)) {
                L = index = mid + 1;
            }
            else R = mid;
        }

        int l = 0;
        int r = index;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a.get(mid) == b) return mid;
            else if(a.get(mid) < b) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        l = index;
        r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a.get(mid) == b) return mid;
            else if(a.get(mid) < b) {
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
