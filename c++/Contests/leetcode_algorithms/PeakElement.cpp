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
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin() , INT_MIN);
        a.insert(a.end() , INT_MIN);

        int l = 1;
        int r = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a[mid] > a[mid + 1] && a[mid] > a[mid - 1]) {
                return mid - 1;
            }
            if(a[mid] < a[mid - 1]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
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
