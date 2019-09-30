#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();
        set < int > a[N + 1];
        for(auto j : trust) {
            a[j[1]].insert(j[0]);
        }
        set < int > check;
        rep(i , 1 , N) {
//            cout << a[i].size() << endl;
            if(a[i].size() == N - 1) {
                check.insert(i);
            }
        }
        for(auto j : check) {
            bool flag = false;
            rep(i , 1 , N) {
                if(a[i].find(j) != a[i].end()) {
                    flag = true;
                }
            }
            if(flag) continue;
            else return j;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
