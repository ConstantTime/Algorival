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
    int firstUniqChar(string s) {
        int n = s.length();
        map < char , int > a;
        set < char > res;
        for(auto j : s) a[j]++;
        for(auto j : a) {
            if(j.second == 1) {
                res.insert(j.first);
            }
        }      
        if(res.size() == 0) {
            return -1;
        }
        rep(i , 0 , n - 1) {
            if(res.find(s[i]) != res.end()) return i;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
