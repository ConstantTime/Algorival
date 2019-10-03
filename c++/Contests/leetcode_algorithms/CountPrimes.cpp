#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 1534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int spf[N + 1];
void sieve(int n) {
    spf[1] = 1;
    for(int i = 2 ; i < n ; i++) spf[i] = i;
    for(int i = 4 ; i < n ; i += 2) spf[i] = 2;
    for (int i = 3 ; i * i < n ; i++) {
        if (spf[i] == i) {
            for (int j = i * i ; j < n ; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

class Solution {
public:
    int countPrimes(int n) {
        sieve(n + 5);
        int cnt = 0;
        rep(i , 2 , n - 1) {
            if(spf[i] == i) cnt++;
        }
        return cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
