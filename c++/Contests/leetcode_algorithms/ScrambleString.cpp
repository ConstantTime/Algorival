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
    bool isScramble(string a, string b) {
        int n = a.length();
        int m = b.length();
        return doit(a , b , 0 , n - 1 , 0 , m - 1);
    }
    bool doit(string a , string b , int x , int y , int u , int v) {
        if(y - x != v - u) return false;
        if(y - x == 0 && a[x] == b[u]) return true;
        int cnt[256] = {0};
        rep(i , x , y) {
            cnt[a[i]]++;
        }
        rep(i , u , v) {
            cnt[b[i]]--;
        }
        rep(i , 0 , 255) {
            if(cnt[i] != 0) return false;
        }
        rep(i , x , y - 1) {
            if(doit(a , b , x , i , u , u + i - x) &&
                doit(a , b , i + 1 , y , v - (y - i - 1) , v))
                return true;

            if(doit(a , b , x , i , v - i + x , v) &&
                doit(a , b , i + 1 , y , u , u + y - (int)(i + 1)))
                return true;
        }
        return false;
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
