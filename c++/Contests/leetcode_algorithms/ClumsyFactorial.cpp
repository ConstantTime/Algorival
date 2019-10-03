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
    int clumsy(int n) {
        int cnt = 0;
        ll pos = n;
        vector < int > ans;
        per(i , n - 1 , 1) {
            if(cnt % 4 == 0) {
                pos = pos * i;
            }
            else if(cnt % 4 == 1) {
                pos = pos / i;
            }
            else if(cnt % 4 == 2) {
                ans.push_back(pos);
                ans.push_back(i);
                pos = INT_MIN;
            }
            else {
                pos = -i;
            }
            cnt++;
        } 
        if(pos != INT_MIN) {
            ans.push_back(pos);
        }
        int sum = 0;
        for(auto j : ans) sum += j;
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    Solution s;
    cout << s.clumsy(4) << endl;
    return 0;
}
