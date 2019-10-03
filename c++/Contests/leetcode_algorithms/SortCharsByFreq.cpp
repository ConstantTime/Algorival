#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 1534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map < char , int > a;
        for(auto j : s) a[j]++;
        vector < pair < int , char > > ans;

        for(auto j : a) {
            ans.push_back({j.second , j.first});
        }

        sort(ans.begin() , ans.end() , 
            greater < pair < int , char > > ());

        string res = "";
        for(auto j : ans) {
            rep(i , 1 , j.first) {
                res += j.second;
            }
        }
        return res;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
