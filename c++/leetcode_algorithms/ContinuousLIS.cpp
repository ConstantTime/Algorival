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

class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int n = a.size();
        int maxi = 0;
        int len = 1;
        if(n == 0) {
            return 0;
        }
        int prev = a[0];
        rep(i , 1 , n - 1) {
            if(a[i] > prev) {
                prev = a[i];
                len++;
            }
            else {
                prev = a[i];
                maxi = max(maxi , len);
                len = 1;
            }
        }
        maxi = max(maxi , len);

        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
