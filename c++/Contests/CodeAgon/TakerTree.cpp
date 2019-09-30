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

vector < int > a[N];

pair < int , int > bfs(int s) {
	int dis[N];
	rep(i , 0 , N - 1) dis[i] = -1;

	queue < int > q;
	q.push(s);

	dis[s] = 0;

	while(!q.empty()) {
		int t = q.front();
		q.pop();

		for(auto j : a[t]) {
			if(dis[j] == -1) {
				q.push(j);
				dis[j] = dis[t] + 1;
			}
		}
	}

	int maxi = 0;
	int node = 0;

	rep(i , 0 , N - 1) {
		if(dis[i] > maxi) {
			maxi = dis[i];
			node = i;
		}
	}

	return make_pair(node , maxi);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);


    vector < int > ans;

    rep(n , 1 , 63) {
	    rep(i , 1 , n) {
	    	int j = (i & (i - 1));
	    	a[j].push_back(i);
	    	a[i].push_back(j);
	    }
	    
	    pair <int , int > t = bfs(0);
	    t = bfs(t.first);
	    ans.push_back(t.second);
	}

	for(auto j : ans) cout << j << " ";
	cout << endl;
    
    return 0;
}
