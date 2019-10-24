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
    int shortestSubarray(vector<int>& aa, int k) {
        int n = a.size();
        int pre[n];
        fill(pre , pre + n , 0);
        rep(i , 1 , n - 1) {
            pre[i] = pre[i - 1] + aa[i];
        }
        int ans = n + 1;
        deque < int > a;
        rep(i , 0 , n - 1) {

            while(a.size() != 0 && pre[i] <= pre[(*a.rbegin())]) {
                a.pop_back();
            }
            while(a.size() != 0 && pre[i] >= pre[(*a.begin())] + k) {
                ans = min(ans , i - (*a.begin()));
                a.pop_front();
            }
            a.add(i);
        }
        return ans < n + 1 ? ans : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
