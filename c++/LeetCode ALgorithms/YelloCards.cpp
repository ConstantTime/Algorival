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
    string s , t;

    cin >> n >> s >> t;

    string a = "";
    string b = "";

    vector < int > ab , ba;
    rep(i , 0 , n - 1) {
        if(s[i] != t[i]) {
            a += s[i];
            b += t[i];
            if(s[i] == 'a') {
                ab.push_back(i + 1);
            }
            else {
                ba.push_back(i + 1);
            }
        }
    }

    // sort(a.begin() , a.end());
    // sort(b.begin() , b.end());

    // if(a != b) {
    //     cout << -1 << endl;
    //     return 0;
    // }

    vector < pair < int , int > > res;

    int m1 = ab.size();
    int m2 = ba.size();

    if(m1 % 2 != m2 % 2) {
        cout << -1 << endl;
        return 0;
    }    

    if(m1 % 2 == 0) {
        rep(i , 0 , m1 - 1) {
            res.push_back({ab[i] , ab[i + 1]});
            i++;
        }
        rep(i , 0 , m2 - 1) {
            res.push_back({ba[i] , ba[i + 1]});
            i++;
        }
    }
    else {
        int k = ab[ab.size() - 1];
        ba.push_back(k);
        ab.pop_back();
        res.push_back({k , k});
        m1 = ab.size();
        m2 = ba.size();
        rep(i , 0 , m1 - 1) {
            res.push_back({ab[i] , ab[i + 1]});
            i++;
        }
        rep(i , 0 , m2 - 1) {
            res.push_back({ba[i] , ba[i + 1]});
            i++;
        }
    }

    cout << res.size() << endl;

    for(auto j : res) {
        cout << j.first << " " << j.second << endl;
    }
    return 0;
}
