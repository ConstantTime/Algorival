#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        if(n == 0) return 0;
        int maxi[n];
        maxi[0] = a[0];
        int mini[n];
        mini[n - 1] = a[n - 1];
        rep(i , 1 , n - 1) {
            maxi[i] = max(maxi[i - 1] , a[i]);
        }
        per(i , n - 2 , 0){
            mini[i] = max(mini[i + 1] , a[i]);
        }
        int res = 0;
        rep(i , 0 , n - 1) {
            res += min(maxi[i] , mini[i]) - a[i];
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
        
    cin >> a;

    cout << longestPalindrome(a) << endl;

    return 0;
}
