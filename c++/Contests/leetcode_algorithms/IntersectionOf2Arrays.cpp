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
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        unordered_map < int , int > A , B;
        for(auto j : a) A[j]++;
        for(auto j : b) B[j]++;
        vector < int > res;
        for(auto j : A) {
            int one = j.second;
            int two = B[j.first];
            if(min(one , two) == 0) {
                continue;
            }
            rep(i , 1 , min(one , two)) {
                res.push_back(j.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
