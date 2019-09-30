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
    int findNthDigit(int n) {
        if(n <= 9) return n;
        ll base = 9;
        ll digits = 1;
        ll start = 1;
        ll end = 9;
        while(n - base * digits > 0) {
            start *= 10;
            end *= 10;
            n -= base * digits;
            digits++;
            base *= 10;
        }

        ll exp = start + (n - 1) / digits;
        vector < int > a;

        while(exp != 0) {
            a.push_back(exp % 10);
            exp /= 10;
        }

        reverse(a.begin() , a.end());
        return a[(n - 1) % digits];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
