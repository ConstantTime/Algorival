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
    int maximumSum(vector<int>& a) {
    	int n = a.size();
    	int l[n];
    	int r[n];
    	fill(l , l + n , 0);
    	fill(r , r + n , 0);
    	l[0] = a[0];
    	int maxi = a[0];
    	for(int i = 1 ; i < n ; i++) {
    		l[i] = max(a[i] , l[i - 1] + a[i]);
    		maxi = max(maxi , l[i]);
    	}
    	r[n - 1] = a[n - 1];
    	maxi = max(maxi , r[n - 1]);
    	for(int i = n - 2 ; i >= 0 ; i--) {
    		r[i] = max(r[i + 1] + a[i] , a[i]);
    		maxi = max(maxi , r[i]);
    	}

    	for(int i = 1 ; i < n - 1 ; i++) {
    		maxi = max(maxi , l[i - 1] + r[i + 1]);
    	}
    	return maxi;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}