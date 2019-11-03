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
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        int lis[n + 1];
        fill(lis , lis + n + 1 , 1);
        int cnt[n + 1];
        fill(cnt , cnt + n + 1 , 1);

        rep(i , 1 , n - 1) {
            rep(j , 0 , i - 1) {
                if(a[j] < a[i]) {
                    if(lis[j] >= lis[i]) {
                        lis[i] = 1 + lis[j];
                        cnt[i] = cnt[j];
                    }
                    else if(1 + lis[j] == lis[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int maxi = 0;
        int ans = 0;

        rep(i , 0 , n - 1) {
            maxi = max(maxi , lis[i]);
        }

        rep(i , 0 , n - 1) {
            if(lis[i] == maxi) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}