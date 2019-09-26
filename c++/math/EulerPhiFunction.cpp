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

int phi(int n){
    int res = n;
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            res /= i;
            res *= i - 1;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n > 1){
        res /= n;
        res *= n - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    return 0;
}
