#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 353456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    int n;
    int k;
    cin >> n >> k;

    rep(i , 1 , n) cin >> a[i];

    set < int > res;
    queue < pair < int , int > > ans;
    int num = n;
    rep(i , 1 , n) {
        if(ans.size() == 0) {
            ans.push({num , a[i]});
            res.insert(a[i]);
            num--;
            continue;
        }
        
        auto j = res.find(a[i]);
        if(j != res.end()) continue;
        if(res.size() == k) {
            auto j = ans.front();
            res.erase(j.second);
            ans.pop();
        }
        res.insert(a[i]);
        ans.push({num , a[i]});

        // queue < pair < int , int > > q;

        // q = ans;

        // while(!q.empty()) {
        //     cout << q.front().second << " ";
        //     q.pop();
        // }
        // cout << endl;
        num--;
    }

    vector < pair < int , int > > check;

    while(!ans.empty()) {
        check.push_back(ans.front());
        ans.pop();
    }

    sort(check.begin() , check.end());;

    cout << check.size() << endl;
    for(auto j : check) {
        cout << j.second << " ";
    }
    cout << endl;
    
    return 0;
}
