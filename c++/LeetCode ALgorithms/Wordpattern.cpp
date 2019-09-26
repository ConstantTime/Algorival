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

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.length();
        int i = 0;
        string ans = "";
        bool flag = true;
        unordered_map < string , char > res;
        for(auto j : str) {
            if(j == ' ') {
                if(res.find(ans) == res.end()) {
                    res[ans] = pattern[i];
                }
                else {
                    if(res[ans] != pattern[i]) {
                        flag = false;
                        break;
                    }
                }
                ans = "";
                i++;
            }
            else {
                ans += j;
            }
        } 
        if(res.find(ans) == res.end()) {
            res[ans] = pattern[i];
        }
        else {
            if(res[ans] != pattern[i]) {
                flag = false;
            }
        }
        unordered_map < char , string > check;
        for(auto j : res) {
            if(check.find(j.second) == check.end()) {
                check[j.second] = j.first;
            }
            else {
                if(check[j.second] != j.first) flag = false;
            }
        } 
        return flag;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    cout << convert(4) << endl;
    
    return 0;
}
