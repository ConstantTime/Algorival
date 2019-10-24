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
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map < int , int > a;
        for(auto j : A) a[j]++;
        ll res = 0;

        for(auto ii : a) {
          for(auto jj : a) {
            int i = ii.first;
            int j = jj.first;
            int sum = target - i - j;
            int k = sum;
            if(a.find(sum) == a.end()) continue;
            ll n = a[i];
            if(i == j && j == k) {
              res += (n * (n - 1) * (n - 2)) / 6;
            }
            else if(i == j && j != k) {
              res += (n * (n - 1)) / 2 * a[sum];
            }
            else if(i < j && j < k) {
              res += a[i] * a[j] * a[k];
            }
            res %= mod;
          }
        }

        return res % mod;
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
