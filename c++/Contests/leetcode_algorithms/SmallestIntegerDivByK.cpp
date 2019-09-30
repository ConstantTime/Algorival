#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153457;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        int cur = 1;
        int sum = cur % k;

        while(sum != 0) {
        	sum *= 10;
        	sum += 1;
        	sum = sum % k;
        	cur++;
        }

        return cur;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    Solution s;

    int k;
    cin >> k;
    cout << s.smallestRepunitDivByK(k) << endl;
    return 0;
}
