#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 1534567;
const long long mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

string binary(int n) {
    string ans = "";
    while(n > 0) {
        ans += to_string(n % 2);
        n = n / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int CNT(string s) {
    int cnt = 0;
    for(auto j : s) {
        if(j == '1') cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    rep(i , 1 , 100) {
        cout<< CNT(binary(i)) << " ";
    }
    cout << endl;
    return 0;
}
