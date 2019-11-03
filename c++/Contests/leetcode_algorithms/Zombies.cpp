#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 100005;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int a[N];
int d[N];
vector < pair < int , int > > ans[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int T;
    cin >> T;

    rep(pp , 1 , T) {
        int n , m;
        cin >> n >> m;
        priority_queue < pair < int , int > > s;
        
        rep(i , 1 , n) cin >> a[i];

        rep(i , 1 , m) {
            int l , r , k;
            cin >> l >> r >> k;
            ans[l].emplace_back(r , k);
        }  
        bool flag = true;
        int answer = 0;
        int dmg = 0;
        rep(i , 1 , n) {
            dmg -= d[i];
            for(auto p : ans[i]) {
                s.push(p);
            }
            a[i] -= dmg;
            while(a[i] > 0) {
                if(s.empty() || s.top().first < i) {
                    flag = false;
                    break;
                }
                int R , K;
                tie(R , K) = s.top();
                s.pop();
                int D = min(a[i] , K);
                a[i] -= D;
                K -= D;
                answer += D;
                dmg += D;
                d[R + 1] += D;
                if(K != 0) {
                    s.push({R , K});
                }
            }
            if(a[i] != 0 || flag == false) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout << "YES " << answer << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
        fill_n(d + 1, N, 0);
        fill_n(ans + 1, N, vector<pair<int, int> >(0));
    }
    
    return 0;
}