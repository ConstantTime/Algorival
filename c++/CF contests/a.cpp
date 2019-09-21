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
long long a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    string s;
    cin >> n >> s;

    int a = 0;
    int b = 0;

    int index = 0;
    int ops = 0;
    rep(i , 0 , n - 1) {
        if(s[i] == 'a') a++;
        else b++;
        if(i % 2 == 0) continue;
        if(a == b) continue;
        if(a > b) {
            while(a != b) {
                if(s[index] == 'a') {
                    s[index] = 'b';
                    a--;
                    b++;
                    ops++;
                    index++;
                }
            }
        }
        else {
            while(a != b) {
                if(s[index] == 'b') {
                    s[index] = 'a';
                    b--;
                    a++;
                    ops++;
                    index++;
                }
            }
        }
    }

    cout << ops << endl;
    cout << s << endl;

    return 0;
}
