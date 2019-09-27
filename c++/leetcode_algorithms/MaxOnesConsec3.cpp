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
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int res = 0;
        for(int i = 0 , start = 0 , flips = 0 ; i < n ; i++) {
            flips += 1 - A[i];
            while(flips > K) {
                if(A[start++] == 0) flips--;
            }
            res = max(res , i - start + 1);
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
