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
    vector<int> sortArrayByParity(vector<int>& A) {
        vector < int > even , odd;
        for(auto j : A) {
            if(j % 2 == 0) {
                even.push_back(j);
            }
            else {
                odd.push_back(j);
            }
        }
        A.clear();
        for(auto j : even) {
            A.push_back(j);
        }
        for(auto j : odd) {
            A.push_back(j);
        }
        return A;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
