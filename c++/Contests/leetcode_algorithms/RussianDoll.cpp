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
    int maxEnvelopes(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        if(n <= 1) return n;
        int lis[n + 1];
        fill(lis , lis + n + 1 , 1);
        
        rep(i , 0 , n - 1) {
            cout << a[i][0] << " " << a[i][1] << endl;
        }
        rep(i , 1 , n - 1) {
        	rep(j , 0 , i - 1) {
        		if(a[j][0] < a[i][0] && a[j][1] < a[i][1]) {
        			lis[i] = max(lis[i] , 1 + lis[j]);
        		}
        	}
        }

        int maxi = INT_MIN;
        rep(i , 0 , n - 1) maxi = max(maxi , lis[i]);
        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
