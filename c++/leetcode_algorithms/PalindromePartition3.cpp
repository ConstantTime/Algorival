#include <bits/stdc++.h>
 
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 153456;
const long long mod = 1e18 + 7;
const long double eps = 1e-6;
const long double pi = 3.1415926535;

bool isPalin(string s , int st , int e) {
    int l = st;
    int r = e;
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
void doit(vector < vector < string > > &ans , vector < string > &res , 
    string s , int index) {

    if(index == s.size()) {
        ans.push_back(res);
        return ;
    }

    rep(i , index , s.length() - 1) {
        if(isPalin(s , index , i)) {
            res.push_back(s.substr(index , i - index + 1));
            doit(ans , res , s , i + 1);
            res.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector < vector < string > > ans;
        vector < string > res;
        if(s.size() == 0) return ans;
        int index = 0;
        doit(ans , res , s , index);
        return ans;    
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
