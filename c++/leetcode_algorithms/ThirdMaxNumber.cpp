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
    int thirdMax(vector<int>& nums) {
        ll max1 = LLONG_MIN;
        ll max2 = LLONG_MIN;
        ll max3 = LLONG_MIN;
        for(ll j : nums) {
        	if(j == max1 || j == max2 || j == max3) continue;
        	if(max1 == LLONG_MIN || j > max1) {
        		max3 = max2;
        		max2 = max1;
        		max1 = j;
        	}
        	else if(max2 == LLONG_MIN || j > max2) {
        		max3 = max2;
        		max2 = j;
        	}
        	else if(max3 == LLONG_MIN || j > max3) {
        		max3 = j;
        	}
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
