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
    string nearestPalindromic(string s) {
        int n = s.length();
        int l = n;
        set < ll > a;
        a.insert(pow(10 , l) + 1);
        a.insert(pow(10 , l - 1) - 1);
        long pre = stol(s.substr(0 , (l + 1) / 2));
        rep(i , -1 , 1) {
            string p = to_string(pre + i);
            string pp = p + string(p.rbegin() + (n & 1) , 
                p.rend());
            a.insert(stol(pp));
        }

        long num = stol(s);
        long mini = LLONG_MAX;
        long diff , val;
        for(long val1 : a) {
            if(val1 == num) continue;
            diff = abs(val1 - num);
            if(diff < mini) {
                mini = diff;
                val = val1;
            }
            else if(diff == mini) {
                val = min(val , val1);
            }
        }
        return to_string(val);
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
