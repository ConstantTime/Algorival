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
    int oddEvenJumps(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        rep(i , 0 , n - 1) {
            bool flag = true;
            
            if(flag) cnt++;
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