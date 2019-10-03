#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    void doit(vector < vector < int > > &ans , 
        vector < int > res , vector < int > &a , int i) {

        cout << i << endl;
        if(i == a.size() && res.size() >= 2) {
            ans.push_back(res);
            return ;
        }
        res.push_back(a[i]);
        doit(ans , res , a , i + 1);
        res.pop_back();
        doit(ans , res , a , i + 1);
    }
    vector<vector<int>> findSubsequences(vector<int>& a) {
        int n = a.size();
        int i = 0;
        vector < vector < int > > ans;
        vector < int > res;
        doit(ans , res , a , i);
        vector < vector < int > > check;
        for(auto j : ans) {
            bool flag = true;
            rep(i , 1 , j.size() - 1) {
                if(j[i] >= j[i - 1]) continue;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                check.push_back(j);
            }
        }
        return check;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
