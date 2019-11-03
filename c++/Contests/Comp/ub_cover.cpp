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

int n , m;
vector < pair < int , int > > a[25];
int dist[(1 << 21)][25];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n >> m;

    rep(i , 1 , m) {
        int x , y , z;
        cin >> x >> y >> z;
        x--;
        y--;
        a[x].push_back({y , z});
        a[y].push_back({x , z});
    }

    int x = (1 << n);
    rep(i , 0 , x) {
        rep(j , 0 , n) dist[i][j] = INT_MAX;
    }

    priority_queue < pair < int , int > ,
    vector < pair < int , int > > , greater < pair < int , int > > > q;
    q.push({(1 << 0) , 0});
    dist[1][0] = 0;
    int ans = 0;

    while(!q.empty()) {
        pair < int , int > temp = q.top();
        q.pop();
        int d = dist[temp.first][temp.second];
        for(auto child : a[temp.second]) {
            int cover = (temp.first | (1 << child.first));
            if(d + child.second < dist[cover][child.first]) {
                dist[cover][child.first] = d + child.second;
                q.push({cover , child.first});
            }
        }

    }

    ans = INT_MAX;
    int index = -1;

    // rep(i , 0 , n - 1) {
    //     if(dist[x - 1][i] < ans) {
    //         ans = dist[x - 1][i];
    //         index = i;
    //     }
    // }
    cout << dist[x - 1][n - 1] << endl;
    //cout << ans << " " << index << endl;
    return 0;
}
