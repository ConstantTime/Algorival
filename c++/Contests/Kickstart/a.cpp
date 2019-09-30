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

ll a[N];
ll dp[N];

string ss = "Case #";
void print(ll pp , ll ans) {
	cout << ss << "" << pp << ": " << ans << endl;
}

int alter(int n) {
	int ans = 0;
	rep(i , 1 , n - 1) {
		if(a[i] != a[i + 1]) ans++;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int t;
    cin >> t;

    rep(pp , 1 , t) {
    	int n , k;
    	cin >> n >> k;
    	rep(i , 1 , n) cin >> a[i];
    	
    	map < int , int > ans;
    	rep(i , 1 , n) ans[a[i]]++;

    	vector < pair < int , int > > res;
    	for(auto j : ans) {
    		res.push_back({j.second , j.first});
    	}

    	sort(res.begin() , res.end() , greater < 
    		pair < int , int > > ());

    	int cnt = 0;

    	if(res.size() <= k) {
    		print(pp , 0);
    		continue;
    	}

    	rep(i , k , res.size() - 1) {
    		cnt += res[i].first;
    	}
    	
    	print(pp , cnt);
    }
    return 0;
}
