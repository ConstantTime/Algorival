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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        map < int , int > a;
        int maxi = 0;
        int len = 0;
        int j = 0;
        rep(i , 0 , n - 1) {
            a[s[i]]++;
            len++;
            if(a.size() <= 2) {
                maxi = max(maxi , len);
            }
            else {
                while(a.size() > 2) {
                    a[s[j]]--;
                    if(a[s[j]] == 0) {
                        a.erase(s[j]);
                    }
                    len--;
                    j++;
                }
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
