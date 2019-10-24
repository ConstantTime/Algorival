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
    int prob(vector < int > &a , int k) {
        int n = a.size();
        map < int , int > ans;
        int cnt = 0;
        int j = 0;

        rep(i , 0 , n - 1) {
            if(!ans[a[i]]++) k--;
            while(k < 0) {
                if(!--ans[a[j]]) k++;
                j++;
            }
            cnt += i - j + 1;
        }   

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& a , int k) {
        int n = a.size();
        int cnt1 = prob(a , k);
        int cnt2 = prob(a , k - 1);
        return cnt1 - cnt2;

    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
