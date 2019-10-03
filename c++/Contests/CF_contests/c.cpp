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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;
        string a , b;
        cin >> a >> b;

        rep(i , 0 , n - 1) {
            int j = a[i] - '1' + 1;
            if(j == 1 || j == 2) {
                a[i] = 'a';
            }
            else {
                a[i] = 'c';
            }
        }

        rep(i , 0 , n - 1) {
            int j = b[i] - '1' + 1;
            if(j == 1 || j == 2) {
                b[i] = 'a';
            }
            else {
                b[i] = 'c';
            }
        }

        bool flag = true;
        bool up = true;
        rep(i , 0 , n - 1) {
            if(a[i] == b[i] && a[i] == 'c') {
                up = !up;
                continue;
            }
            if(up == true) {
                if(a[i] == 'c' && b[i] == 'a') {
                    flag = false;
                    break;
                }
            }
            else {
                if(b[i] == 'c' && a[i] == 'a') {
                    flag = false;
                    break;
                }   
            }
        }

        if(up == true) {
            flag = false;
        }


        if(flag == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
