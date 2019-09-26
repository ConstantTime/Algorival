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


string convert(int x) {
    string s = "";
    while(x != 0) {
        s += (x % 2 + '0');
        x = x / 2;
    }
    reverse(s.begin() , s.end());
    return s;
}

class Solution {
public:
    int hammingDistance(int x, int y) {
        string s = convert(x);
        string t = convert(y);
        while(s.length() != 50) {
            s = "0" + s;
        }
        while(t.length() != 50) {
            t = "0" + t;
        }

        int cnt = 0;
        rep(i , 0 , 49) {
            if(s[i] != t[i])
                cnt++;
        }

        return cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    cout << convert(4) << endl;
    
    return 0;
}
