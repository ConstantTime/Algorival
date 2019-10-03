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
    bool isUgly(int num) {
        if(num == 0) {
            return false;
        }
        while(num % 2 == 0) {
            num = num / 2;
        }
        while(num % 3 == 0) {
            num = num / 3;
        }
        while(num % 5 == 0) {
            num = num / 5;
        }
        return (num == 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
