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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();

        priority_queue < ll , vector < ll > , greater < ll > > pq;

        if(m == 1) {
            return pow(primes[0] , n - 1);
        }

        rep(i , 0 , m - 1) {
            pq.push(primes[i]);
        }

        int cnt = 1;
        ll ans = 1;

        while(cnt < n) {
            ans = pq.top();
            pq.pop();
            if(ans != pq.top()) {
                cnt++;
                rep(i , 0 , m - 1) {
                    pq.push(ans * (ll)primes[i]);
                }
            }
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
