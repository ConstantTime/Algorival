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

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m != n) return false;

        bool flag = true;
        unordered_map < char , char > ans;
        rep(i , 0 , n - 1) {
            if(ans.find(s[i]) == ans.end()) {
                ans[s[i]] = t[i];
            }
            else {
                if(ans[s[i]] != t[i]) flag = false;
            }
        }  

        unordered_map < char , char > check;

        for(auto j : ans) {
            if(check.find(j.second) == check.end()) {
                check[j.second] = j.first;
            }
            else {
                if(check.find(j.second) != j.first) flag = false;
            }
        }    

        return flag;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    cout << convert(4) << endl;
    
    return 0;
}
