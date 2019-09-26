#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

map < ll , vector < ll > > res;
int indexed[12];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    string s;
    cin >> s;

    map < char , int > a;

    for(auto j : s) {
        a[j]++;
    }

    int count = 0;

    int size = 0;

    rep(i , 0 , n - 1) {
        if(a[s[i]] % 2 != 0) {
            int num = s[i] - '0';
            res[s[i] - '0'].push_back(i);   
            size = max(size , (int)res[num].size());
        }
    }

    ll ans = INT_MAX;

    ll reps = 5 * N;

    for(auto j : res) {
        if(res[j.first].size() == 0) continue;
        while(res[j.first].size() != size) {
            res[j.first].push_back(reps);
            reps += 5 * N;
        }
    }

    if(res.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    if(res.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    while(1) {
        bool flag = true;
        rep(i , 0 , 11) {
            if(indexed[i] >= size) {
                flag = false;
            }
        }

        if(flag == false) break;

        ll mini = INT_MAX;
        ll maxi = INT_MIN;

        rep(i , 0 , 11) {
            if(res[i].size() == 0) continue;
            mini = min(mini , res[i][indexed[i]]);
            maxi = max(maxi , res[i][indexed[i]]);
        }


        rep(i , 0 , 11) {
            if(res[i].size() == 0) continue;
            if(mini == res[i][indexed[i]]) {
                indexed[i]++;
                break;
            }
        }

        ans = min(ans , maxi - mini);

    }

    cout << ans << endl;
    return 0;
}
