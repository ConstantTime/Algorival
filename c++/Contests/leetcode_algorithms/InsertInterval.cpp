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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int fi = newInterval[0];
        int se = newInterval[1];
        int n = intervals.size();
        bool flag = false;
        vector < int > res;
        int n = intervals.size();

        rep(i , 0 , n - 2) {
            
        }
        if(flag == false) {
            if(fi > intervals[n - 1][1]) {
                res.push_back(fi);
                res.push_back(se);
                intervals.push_back(res);
            }
            else if(se <= intervals[n - 1][1] &&
                fi >= intervals[n - 1][0]) {
                // nothing
            }
            else {
                intervals[n - 1][1] = se;
            }   
        }    
        return intervals;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
