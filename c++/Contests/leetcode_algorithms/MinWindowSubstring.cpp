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
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if(n == 0 || m == 0) return "";
        vector < int > a(128 , 0);
        rep(i , 0 , m - 1) a[t[i]]++;
        int mini = INT_MAX;
        int start = 0;
        int lef = 0;
        int i  =0;
        while(i <= n && start < n) {
            if(m) {
                if(i == n) break;
                a[s[i]]--;
                if(a[s[i]] >= 0) m--;
                i++;
            }
            else {
                if(i - start < mini) {
                    mini = i - start;
                    lef = start;
                }
                a[s[start]]++;
                if(a[s[start]] > 0) m++;
                start++;
            }
        }

        return mini == INT_MAX ? "" : s.substr(lef , mini);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
   
    
    return 0;
}
