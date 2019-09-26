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

pair < int , int > a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    
    rep(i , 1 , n) cin >> a[i].first;

    rep(i , 1 , n) a[i].second = i;

    sort(a + 1 , a + n + 1);
    reverse(a + 1 , a + n + 1);

    int cnt = 0;
    int sum = 0;

    rep(i , 1 , n) {
        sum += a[i].first * cnt + 1;
        cnt++;
    }

    cout << sum << endl;

    rep(i , 1 , n) cout << a[i].second << " ";
    cout << endl;


    return 0;
}
