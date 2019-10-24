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
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int index = -1;
        int L = 0;
        int R = n - 1;

        while(L < R) {
            int mid = (L + R) / 2;
            if(a[mid] < a[mid + 1]) {
                L = index = mid + 1;
            }
            else R = mid;
        }
        return index;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
