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
    bool palindrome(string s) {
        ll i = 0;
        ll j = s.length() - 1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            j-- , i++;
        }
        return true;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        string ans = "";
        rep(i , 0 , n - 1) {
            if(s[i] <= 'Z' && s[i] >= 'A') {
                ans += tolower(s[i]);
            }
            else if(s[i] <= 'z' && s[i] >= 'a') {
                ans += s[i];
            }
            else if(s[i] <= '9' && s[i] >= '0') {
                ans += s[i];
            }
        }
        return palindrome(ans);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
