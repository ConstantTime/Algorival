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
    bool compare(unordered_map < char , int > a , 
        unordered_map < char , int > b) {

        for(auto j : a) {
            if(b[j.first] < j.second) return false;
        } 
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map < char , int > a , b;
        if(m > n) return "";
        // rep(i , 0 , 25)  {
        //     a['A' + i] = 0;
        //     b['A' + i] = 0;
        //     a['a' + i] = 0;
        //     b['a' + i] = 0;
        // }
        rep(i , 0 , m - 1) {
            a[t[i]]++;
            b[s[i]]++;
        }
        if(compare(a , b)) return s.substr(0 , m);
        int len = INT_MAX;
        int index = 0;
        // for(auto j : a) {
        //     cout << j.first << " " << j.second << endl;
        // }
        int ans = -1;
        rep(i , m , n - 1) {
            b[s[i]]++;
       //     cout << index << endl;
            if(compare(a , b)) {
                
                while(1) {
                    b[s[index]]--;
                    if(compare(a , b) == false) {
                        b[s[index]]++;
                        if(len > i - index + 1) {
                            len = i - index + 1;   
                            ans = index;
                        }
                        break;
                    }
                    index++;
                }
            }
            
            // if(len <= 4) {
            //     cout << i << " " << index << " " << len << endl;
            //     // for(auto j : b) {
            //     //     cout << j.first << " " << j.second << endl;
            //     // }
            // }
        }
        
        // cout << index << " " << index << " " << len << endl;
        // for(auto j : b) {
        //     cout << j.first << " " << j.second << endl;
        // }
        
        if(compare(a , b)) {
            while(1) {
                b[s[index]]--;
                if(compare(a , b) == false) {
                    if(len > n - index + 1) {
                        len = n - index + 1;
                        ans = index;
                    }
                    break;
                }
                index++;
            }
        }
        if(len == INT_MAX) return "";
        return s.substr(ans , len);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
