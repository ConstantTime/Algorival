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
    string addStrings(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        int carry = 0;
        string s = "";
        if(n < m) {
            swap(num1 , num2);
        }
        while(num2.length() != n) {
            num2 = "0" + num2;
        }
        per(i , n - 1 , 0) {
            int num = num1[i] - '0' + num2[i] - '0' +
                        carry;
            carry = num / 10;
            num = num % 10;
            s += to_string(num);
        }
        if(carry != 0) {
            s = s + to_string(carry);
        }
        reverse(s.begin() , s.end());
        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
