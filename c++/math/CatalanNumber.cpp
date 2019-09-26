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

long long BinomialCoffecient(long long n , long long k) {
    long long res = 1;
    if(k > n - k) k = n - k;
    for(int i = 0 ; i < k ; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
long long Catalan(long long n) {
    return BinomialCoffecient(2 * n , n) / (n + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    return 0;
}
