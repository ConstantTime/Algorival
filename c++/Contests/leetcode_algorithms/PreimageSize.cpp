#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int count(int value , int d) {
        int cnt = 0;

        for(int j = 1 ; j <= value ; j *= 10) {
            int div = j * 10;
            int q = value / div;
            cnt += q * j;
            if(d == 0) cnt -= j;
            int rem = value % div;
            cnt += min(max(rem - d * j + 1 , 0) , j);
        }

        return cnt;
    }
    int digitsCount(int d, int low, int high) {
        if(d < 0 || high < 0) return 0;
        return count(high , d) - count(low - 1 , d);
    }
    int f(int n) {
        int cnt = 0;
        int p = 5;
        while(n != 0) {
            cnt += n / p;
            n = n / p;
        }
        return cnt;
    }
    int preimageSizeFZF(int k) {
        int l = 0;
        int r = 1e9;
        int ans = -1;
        while(l < r) {
            int mid = (l + r) / 2;
            cout << l << " " << r << endl;
            if(f(mid) > k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        int s , e;
        e = ans;
        l = 0;
        r = 1e9;
        while(l < r) {
            int mid = (l + r) / 2;
            if(f(mid) < k) {
                l = mid + 1;

            }
            else {
                r = mid;
            }   
        }
        s = l;
        
       cout << s << " " << e << endl;

        return max(e - s + 1 , 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
        
    cin >> a;

    cout << longestPalindrome(a) << endl;

    return 0;
}
