#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 353456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    
    rep(i , 1 , 9) {
        rep(j , 1 , 9) {
            if(i * j == n) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }    

    cout << "No" << endl;
    return 0;
}
