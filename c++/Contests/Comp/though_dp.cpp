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

ll n;
ll dp1[N];
ll dp[N];
ll a[N];
ll nck[3333][3333];
int LOG[N];

ll choose(ll n , ll k) {
    if(n < k) return 0;
    if(k == 0) return 1;
    if(n <= 1) return 1;
    if(nck[n][k] != -1) return nck[n][k];
    ll ans = choose(n - 1 , k - 1) + choose(n - 1 , k);
    ans %= mod;
    nck[n][k] = ans;
    return ans;
}

ll getL(int n) {
    if(n == 1) return 0;
    int h = LOG[n];
    int numh = (1 << h);
    int last = n - numh + 1;
    if(last >= numh / 2) {
        return numh - 1;
    }
    return numh - 1 - ((numh / 2) - last);
}

ll maxHeaps2(ll n) {
    if(n <= 2) return 1;
    if(dp1[n] != -1) return dp1[n];
    int L = getL(n);
    ll ans = ((choose(n - 1 , L) * maxHeaps2(L)) % mod) * 
    maxHeaps2(n - 1 - L);
    ans %= mod;
    dp1[n] = ans;
    return ans; 
}

ll maxHeaps(ll n) {
    if(n <= 2) return 1;
    if(dp[n] != -1) return dp[n];
    int L = getL(n);
    int R = n - 1 - L;
    ll ans = 0;
    ans += (choose(n - 3 , L - 1) * maxHeaps2(L)) % mod * 
    (maxHeaps2(R)) % mod;   
    ans %= mod;
    ans += (choose(n - 3 , L) * maxHeaps2(L)) % mod * 
    (maxHeaps2(R)) % mod;   
    ans %= mod;
    ans += (choose(n - 3 , R) * maxHeaps2(L)) % mod * 
    (maxHeaps2(R)) % mod;   
    ans %= mod;
    dp[n] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    cin >> n;

    // rep(i , 1 , n) cin >> a[i];

    rep(i , 1 , n) a[i] = i;

    sort(a + 1 , a + n + 1);    

    fill(dp , dp + N , -1);
    fill(dp1 , dp1 + N , -1);

    rep(i , 0 , n) rep(j , 0 , n) nck[i][j] = -1;

    ll power = 1;
    ll lo = -1;
    rep(i , 1 , n) {
        if(power == i) {
            lo++;
            power *= 2;
        }
        LOG[i] = lo;
    }

    if(a[n] == a[n - 1]) {
        cout << maxHeaps(n) << endl;
        return 0;
    }

    cout << maxHeaps2(n) << endl;
    
    return 0;
}