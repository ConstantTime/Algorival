#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153457;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        int num = 1;
        per(i , n - 1 , 0) {
            digits[i] += num + carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
            if(carry == 0) break;
            num = 0;
        }

        if(carry > 0) {
            digits.insert(digits.begin() , carry);
        }

        return digits;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    Solution s;

    int k;
    cin >> k;
    cout << s.smallestRepunitDivByK(k) << endl;
    return 0;
}
