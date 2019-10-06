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
    int kSimilarity(string a, string b) {
    	int n = a.length();
    	int m = b.length();
    	rep(i , 0 , n - 1) {
    		if(a[i] != b[i]) {
	    		vector < int > res;
	    		rep(j , i + 1 , n - 1) {
	    			if(a[j] == b[i] && a[j] != b[j]) {
	    				res.push_back(j);
	    				if(a[i] == b[j]) {
	    					swap(a[i] , a[j]);
	    					return 1 + kSimilarity(
	    						a.substr(i + 1) , b.substr(i + 1));
	    				}
	    			}
	    		}

	    		int ans = n - 1;
	    		for(int j : res) {
	    			swap(a[i] , a[j]);
	    			ans = min(ans , 1 + kSimilarity(
	    				a.substr(i + 1) , b.substr(i + 1)));
	    			swap(a[i] , a[j]);
	    		}
	    		return ans;
	    	}
    	}
    	return 0;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
