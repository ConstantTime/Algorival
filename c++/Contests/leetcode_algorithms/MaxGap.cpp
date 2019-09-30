#include <bits/stdc++.h>
 
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 153456;
const long long mod = 1e18 + 7;
const long double eps = 1e-6;
const long double pi = 3.1415926535;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        rep(i , 0 , n - 1) {
        	maxi = max(maxi , nums[i]);
        	mini = min(mini , nums[i]);
        }
        int gap = (maxi - mini) / (n - 1);
    	if(gap == 0) gap++;
    	int m = (maxi - mini) / gap + 1;
    	vector < int > a(m, INT_MAX) , b(m, INT_MIN);
    	for(auto j : nums) {
    		int k = (j - mini) / gap;
    	//	cout << j << "  " << k << endl;
    		if(j < a[k]) a[k] = j;
    		if(j > b[k]) b[k] = j;
    	}
    	gap = b[0] -  a[0];
    	int i = 0;
    	while(i < m) {
    		int j = i + 1;
    		while(j < m && a[j] == INT_MAX && b[j] == INT_MIN) {
    			j++;
    		}
    		if(j == m) break;
    		gap = max(gap , a[j] - b[i]);
    		i = j;
    	}
    	return gap;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
