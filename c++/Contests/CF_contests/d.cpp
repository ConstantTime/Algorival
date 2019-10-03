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

set < int > a[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    string s;
    cin >> s;

    int q;
    cin >> q;

    int n = s.length();
    rep(i , 0 , n - 1) {
        int j = s[i] - 'a';
        a[j].insert(i + 1);
    }

    while(q--) {
        int t;
        cin >> t;
        if(t == 2) {
            int l , r;
            cin >> l >> r;
            int pos = 0;    
            rep(i , 0 , 25) {
                auto j = a[i].lower_bound(l);
                if(*j >= l && *j <= r) pos++;
            }
            cout << pos << endl;
        }
        else {
            int num;
            char c;
            cin >> num >> c;
            rep(i , 0 , 25) {
                if(a[i].find(num) != a[i].end()) {
                    a[i].erase(num);
                    break;
                }
            }
            a[c - 'a'].insert(num);
        }
        cout << t << endl;
    }
    return 0;
}
