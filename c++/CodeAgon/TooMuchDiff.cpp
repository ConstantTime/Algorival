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

ll a[N];
ll ind[N];
map < ll , vector < ll > > res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    srand(time(NULL));
    int t;
    cin >> t;
    rep(pp , 1 , t) {
        int n;
        ll k;
        cin >> n >> k;  
        ll ans = INT_MAX;

        rep(i , 1 , n) {
            ind[i] = 0;
            res[i].clear();
            cin >> a[i];
        }

        rep(i , 1 , n) {
            if(a[i] % k != 0) {
                res[i].push_back(a[i]);
                res[i].push_back(a[i] * k);
            }
            else {
                ll j = a[i];
                while(j != 0) {
                    res[i].push_back(j);
                    if(j % k != 0) break;
                    j /= k;
                }
                reverse(res[i].begin() , res[i].end());
            }
        }

        ll cover = mod;
        cover *= 5;

        int size = 0;
        rep(i , 1 , n) {
            size = max(size , (int)res[i].size());
        }
        
        rep(i , 1 , n) {
            while(res[i].size() != size) {
                res[i].push_back(cover);
                cover += 2 * mod;
            }
        }


        priority_queue < pair < ll , ll > , vector < pair < ll , ll >
         > ,  greater < pair < ll , ll > > > A;
        priority_queue < ll > B;

        rep(i , 1 , n) {
            if(res[i].size() == 0) continue;
            A.push({res[i][ind[i]] , i});
            B.push(res[i][ind[i]]);
        }

        while(1) {
            if(n == 0) break;

            ll mini = LLONG_MAX;
            ll maxi = LLONG_MIN;
            int indi = -1;

            mini = A.top().first;
            indi = A.top().second;
            A.pop();
            maxi = B.top();

            if(maxi - mini >= INT_MAX) break;
            ans = min(ans , maxi - mini);

            ind[indi]++;
            if(ind[indi] >= size) break;
            A.push({res[indi][ind[indi]] , indi});
            B.push(res[indi][ind[indi]]);

        }

        cout <<  ans << endl;
    }
    return 0;
}
