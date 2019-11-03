#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;
class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int l = a[0];
        int r = a[0];
        int temp = a[0];
        rep(i , 1 , n - 1) {
            if(a[i] < 0) {
                swap(l , r);
            }
            l = min(a[i] , l * a[i]);
            r = max(a[i] , r * a[i]);
            temp = max(temp , r);
        }
        return temp;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}