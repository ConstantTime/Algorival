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
    int numSquares(int n) {
        vector < int > res(n + 1 , 0);
        rep(i , 1 , n) {
            int temp = INT_MAX;

            rep(j , 1 , n) {
                if(i - pow(j , 2) < 0) break;
                int le = 1 + res[i - pow(j , 2)];
                temp = min(le , temp);
            }

            res[i] = temp;
        }      

        return res[n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
