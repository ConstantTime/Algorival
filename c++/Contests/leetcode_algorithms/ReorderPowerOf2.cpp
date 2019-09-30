#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:

    void permute(vector < string > &ans , string s,
         int l , int r) {

        if(l == r) {
            ans.push_back(s);
            return ;
        }

        rep(i , l , r) {
            swap(s[l] , s[i]);
            permute(ans , s , l + 1 , r);
            swap(s[l], s[i]);
        }
    }
    bool reorderedPowerOf2(int n) {
        string s = to_string(n); 
        vector < string > a;
        set < ll > ans;
        rep(i , 0 , 35) {
            ans.insert(pow(2 , i));
        }
        int nn = s.length();
        permute(a , s , 0 , nn - 1);       
        for(auto j : a) {
            if(j[0] == '0') continue;
            int i = stoll(j);
            if(ans.find(i) != ans.end()) return true;
        }
        return false;
    } 
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
