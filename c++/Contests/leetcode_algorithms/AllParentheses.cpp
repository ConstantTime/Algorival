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
    void doit(set < string > &ans , string& res , int n
        , int m) {
        if(n == 0) {
            while(m != 0) {
                res += ')';
                m--;
            }
            ans.insert(res);
            return ;
        }
        res += '(';
        doit(ans , res , n - 1 , m);
        res.pop_back();
        if(n > m) {
            res += ')';
            doit(ans , res , n , m - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        set < string > ans;
        string res = "";
        doit(ans , res , n , n);
        vector < string > ans2;
        for(auto j : ans) ans2.push_back(j);
        return ans2;
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
