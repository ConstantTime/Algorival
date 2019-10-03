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
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        map < int , int > ans;
        vector < int > res;
        if(k == 0 || n == 0) return res;
        rep(i , 0 , k - 1) {
            ans[a[i]]++;
        }
        res.push_back((*ans.rbegin()).first);
        rep(i , k , n - 1) {
            ans[a[i]]++;
            ans[a[i - k]]--;
            if(ans[a[i - k]] == 0) {
                ans.erase(a[i - k]);
            }
            res.push_back((*ans.rbegin()).first);    
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
