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
    int minMoves2(vector<int>& a) {
        int n = a.size();
        ll sum = 0;
        ll res = 0;

        sort(a.begin() , a.end());

        int i = 0;
        int j = n - 1;

        while(i < j) {
            res += a[j] - a[i];
            i++;
            j--;
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
