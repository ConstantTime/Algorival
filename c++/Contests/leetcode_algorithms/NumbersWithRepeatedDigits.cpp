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
    int res = 0;
    void doit(int cur , int mask , int n) {
        if(cur > n) return ;
        else res++;
        rep(digit , 0 , 9) {
            if(mask == 0 && digit == 0) continue;
            if((mask & (1 << digit)) > 0) continue;
            doit(cur * 10 + digit , (mask | (1 << digit)) , n);
        }
    }
    int numDupDigitsAtMostN(int n) {
        vector < int > a;
        int temp = n;

        while(temp != 0) {
            a.push_back(temp % 10);
            temp /= 10;
        }

        reverse(a.begin(), a.end());
        int l = a.size();
        rep(i , 0 , l - 1) {
            ll check = 9;
            ll m = 9;
            ll nn = i;
            while(m > 1 && nn > 0) {
                check *= m;
                m--;
                n--;
            }
            res += check;
        }

        
    }
    int majorityElement(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        int can = -1;
        for(int j : a) {
            if(cnt == 0) can = j;
            cnt += (j == can) ? 1 : -1;
        }
        return can;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
