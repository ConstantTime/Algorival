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

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector < int > res;
        if(n < m) return res;
        map < char , int > a , b;
        rep(i , 0 , m - 1) {
            a[p[i]]++;
            b[s[i]]++;
        }
        if(a == b) {
            res.push_back(0);
        }
        rep(i , m , n - 1) {
            b[s[i]]++;
            b[s[i - m]]--;
            if(b[s[i - m]] == 0) {
                b.erase(s[i - m]);
            }
            if(a == b) {
                res.push_back(i - m + 1);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
