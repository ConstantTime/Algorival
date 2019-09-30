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

bool sq(int n) {
	int r = sqrt(n);
	return r * r == n;
}
void doit(vector < int > A , int index , int& ans) {
	int n = A.size();
	if(index == A.size()) ans++;
	rep(i , index , n - 1) {
		if(i > index && A[i] == A[index]) continue;
		swap(A[i] , A[index]);
		if(index == 0 || (index > 0 && sq(A[index] + A[index - 1]))) {
			doit(A , index + 1 , ans);
		}
	}
}

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {      
    	int n = A.size();  
    	sort(A.begin(), A.end());
    	int ans = 0;
    	doit(A , 0 , ans);
    	return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
