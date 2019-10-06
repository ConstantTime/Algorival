#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 1534567;
const long long mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        unordered_map < int , int > res;
        for(auto j : a) {
            for(auto i : a) {
                res[(i & j)]++;
            }
        }
        int cnt = 0;
        for(auto j : a) {
            for(auto i : res) {
                if((j & i.first) == 0) {
                    cnt += i.second;
                }
            }
        }
        return cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
