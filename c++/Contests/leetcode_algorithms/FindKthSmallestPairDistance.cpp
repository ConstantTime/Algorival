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
    int smallestDistancePair(vector<int>& a, int k) {
        int n = a.size();
        if(n <= 0) return 0;
        sort(a.begin() , a.end());
        int l = 0;
        int r = a[n - 1] - a[0];

        map < int , int > ans;

        rep(i , 0 , n - 1) {
            ans[a[i]] = i;
        }

        while(l < r) {
            int cnt = 0;
            int mid = l + (r - l) / 2;
            rep(i , 0 , n - 1) {
                auto pos = ans.lower_bound(a[i] + mid);
                if(pos == ans.end() || (*pos).first > a[i] + mid) pos--;
                int cur = ((*pos).second - i);
                cnt += cur;
            }
            
            
           // cout << l << " " << r << " " << cnt << endl;

            if(cnt < k) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }

        return l;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
