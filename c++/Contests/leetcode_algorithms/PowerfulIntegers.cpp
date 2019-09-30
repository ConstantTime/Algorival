#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153457;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        ll a = x;
        ll b = y;
        set < ll > ans;
        rep(i , 0 , 60) {
            rep(j , 0 , 60) {
                if(pow(a , i) > INT_MAX || pow(a , i) > bound) break;
                if(pow(b , j) > INT_MAX || pow(b , j) > bound) break;
                if(pow(a , i) + pow(b , j) <= bound) {
                    ans.insert(pow(a , i) + pow(b , j));
                }
            }
        }
        vector < int > res;
        for(auto j : ans) res.push_back(j);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    Solution s;

    int k;
    cin >> k;
    cout << s.smallestRepunitDivByK(k) << endl;
    return 0;
}
