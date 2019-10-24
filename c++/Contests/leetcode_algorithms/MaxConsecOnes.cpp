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
    int minSwaps(vector<int>& a) {
        int n = a.size();
        if(n < 3) return 0;
        int one = 0;
        for(auto j : a) one += j;
        int maxi = 0;
        int i = 0;
        int j = 0;
        int len = 0;

        while(j < n) {
            while(j < n && j - i < one) {
                if(a[j] == 1) len++;
                j++;
            }
            maxi = max(maxi , len);
            if(j == n) break;
            if(a[i] == 1) {
                len--;
                i++;
            }
        }
        return one - maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
