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

    double a , b;
    cin >> a >> b;

    double x;
    cin >> x;

    double n = (x - (a * a * b) / 2.0) / (a * a / 2.0);
    ld ang;
    if(n > 0)
        ang = a / (b - n);
    else {
        ld temp = (2 * x) / (a * b);
        ang = temp / b;        
    }
  //  cout << a << " " << b - n << endl;
    ang = atan(1 / ang) * 180.0 / pi;
    cout << ang << endl;

    return 0;
}
