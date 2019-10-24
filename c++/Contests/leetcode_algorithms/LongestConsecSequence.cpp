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
    map < int , int > cnt;
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        rep(i , 0 , n - 1) {
            cnt[a[i]]++;
        }
        int len = 0;
        int prev = 0;
        int maxi = 0;
        bool flag = false;
        for(auto j : cnt) {
            if(flag == false) {
                flag = true;
                prev = j.first;
                len++;
                continue;
            }
            if(j.first == 1 + prev) {
                len++;
                prev = j.first;
            }
            else {
                maxi = max(maxi , len);
                len = 1;
                prev = j.first;
            }
        }

        maxi = max(maxi , len);

        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
