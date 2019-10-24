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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;

        int len = 0;
        map < int , int > a;
        int st = 0;
        rep(i , 0 , n - 1) {
            a[s[i]]++;
            if(a[s[i]] <= 1) {
                len++;
                maxi = max(maxi , len);
            }
            else {
                while(1) {
                    a[s[st]]--;
                    if(a[s[st]] == 0) {
                        a.erase(a[s[st]]);
                    }
                    len--;
                    st++;
                    if(a[s[i]] == 1) break;
                }
                maxi = max(maxi , len);
            }
        }

        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
