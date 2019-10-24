#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    string lastSubstring(string s) {
        int n = s.length();
        int i = 1;
        int maxi = 0;

        while(i < n) {
            if(s[i] > s[maxi]) {
                maxi = i;
            }
            else if(s[i] == s[maxi]) {
                int cur = i;
                int j = maxi;
                while(i < n && s[j] == s[i] && j < cur) {
                    i++;
                    j++;
                }
                if(i >= n || j >= cur || s[j] > s[i]) {
                    continue;
                }
                maxi = i;
                continue;
            }
            i++;
        }
        return s.substr(maxi);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
        
    cin >> a;

    cout << longestPalindrome(a) << endl;

    return 0;
}
