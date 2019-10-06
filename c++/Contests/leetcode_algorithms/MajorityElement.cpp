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
    int subarrayBitwiseORs(vector<int>& a) {
  		unordered_map < int , int > ans , cur;
  		cur[0]++;
  		for(auto j : a) {
  			unordered_map < int , int > temp;
  			for(auto i : cur) {
                int k = (i.first | j);
  				temp[k]++;
  			}
  			temp[j]++;
  			cur = temp;
  			for(auto k : cur) {
  				ans[k.first]++;
  			}
  		}
  		return ans.size();
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
	