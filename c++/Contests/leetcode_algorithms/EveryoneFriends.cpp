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

class Solution {
public:
    int sz[123456];
    int ind[123456];
    vector < vector < int > > a;
    int find(int j) {
        while(j != ind[j]) {
            j = ind[j];
        }
        return j;
    }
    int Union(int i , int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) return sz[x];
        if(sz[x] > sz[y]) {
            sz[x] += sz[y];
            ind[y] = x;
            return sz[x];
        }
        else {
            sz[y] += sz[x];
            ind[x] = y;
            return sz[y];
        }
    }
    int earliestAcq(vector<vector<int>>& logs, int N) {
        a = logs;
        int n = logs.size();
        rep(i , 0 , 123455) ind[i] = i;
        rep(i , 0 , 123455) sz[i] = 1;
        sort(a.begin(), a.end());
        for(auto j : a) {
            if(Union(j[1] , j[2]) == N) return j[0];
        }

        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
