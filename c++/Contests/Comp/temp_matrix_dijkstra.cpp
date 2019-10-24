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

char a[1234][1234];
int n , m;
map < pair < int , int > , int > dist;
priority_queue < mp , vector < mp > , greater < mp > > p;
int x , y;

void update(int i , int j) {
    bool flag = false;
    if(dist.find({i , j}) == dist.end()) {
        dist[{i , j}] = dist[{x , y}];
        if(a[i][j] == '#') {
            dist[{i , j}]++;
        }
        flag = true;
    }
    else {
        if(a[i][j] == '#') {
            if(1 + dist[{x , y}] < dist[{i , j}]) {
                dist[{i , j}] = 1 + dist[{x , y}];
                flag = true;
            }
        }
        else {
            if(dist[{x , y}] < dist[{i , j}]) {
                dist[{i , j}] = dist[{x , y}];
                flag = true;
            }
        }
    }
    if(flag) {
        p.push({dist[{i , j}] , {i , j}});
    }
}

void dijkstra(pair < int , int > ans) {
    p.push({0 , {ans.first , ans.second}});
    dist[ans] = 0;
    while(!p.empty()) {
        mp t = p.top();
        p.pop();
        x = t.second.first;
        y = t.second.second;
        if(x - 1 >= 1 && a[x - 1][y] != '*') {
            int i = x - 1;
            int j = y;
            update(i , j);
        }

        if(y - 1 >= 1 && a[x][y - 1] != '*') {
            int i = x;
            int j = y - 1;
            update(i , j);
        }

        if(x + 1 <= n && a[x + 1][y] != '*') {
            int i = x + 1;
            int j = y;
            update(i , j);
        }

        if(y + 1 <= m && a[x][y + 1] != '*') {
            int i = x;
            int j = y + 1;
            update(i , j);
        }

    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n >> m;

    rep(i , 1 , n) {
        rep(j , 1 , m) cin >> a[i][j];
    }

    pair < int , int > ans , res;

    rep(i , 1 , n) {
        rep(j , 1 , m) {
            if(a[i][j] == 'A') {
                ans.first = i;
                ans.second = j;
            }
            else if(a[i][j] == 'B') {
                res.first = i;
                res.second = j;
            }
        }
    }

    dijkstra(ans);

    if(dist.find(res) == dist.end()) {
        cout << -1 << endl;
    }
    else {
        cout << dist[res] << endl;
    }

    return 0;
}
