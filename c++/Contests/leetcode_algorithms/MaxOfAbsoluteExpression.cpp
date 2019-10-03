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
    int f(vector < int > &a) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto j : a) {
            maxi = max(maxi , j);
            mini = min(mini , j);
        }
        return maxi - mini;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        vector < int > a , b , c , d;
        rep(i , 1 , n) {
            a.push_back(0);
            b.push_back(0);
            c.push_back(0);
            d.push_back(0);
        }

        rep(i , 0 , n - 1) {
            a[i] = arr1[i] + arr2[i] + i;
            b[i] = arr1[i] - arr2[i] + i;
            c[i] = arr1[i] + arr2[i] - i;
            d[i] = arr1[i] - arr2[i] - i;
        }

        return max(max(f(a) , f(b)) , max(f(c) , f(d)));
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
