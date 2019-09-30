#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

ll a[N];
int lef = 0;
int rig = 0;
class Solution {
public:
    int smallestRangeII(vector<int>& A, int k) {
		int n = A.size();
		sort(A.begin() , A.end());
		lef = A[0] + k;
		rig = A[n - 1] - k;

		int res = A[n - 1] - A[0];
		if(n <= 1) return res;
		rep(i , 0 , n - 2) {
			int maxi = max(A[i] + k , rig);
			int mini = min(lef , A[i + 1] - k);
			res = min(res , maxi - mini);
		}

		return res;

    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
