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
    map < int , int > a;
    int ind[N];
    int sz[N];
    check < int > check[N];
    int find(int i) {
        while(i != ind[i]) {
            i = ind[i];
        }
        return i;
    }
    int Union(int i , int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) return ;
        if(x < y) {
            ind[y] = x;
        }
        else {
            ind[x] = y;
        }
    }
    string smallestEquivalentString(string A, string B, string S) {
        int n = A.length();
        rep(i , 0 , N - 1) ind[i] = i;
        rep(i , 0 , N - 1) sz[i] = 1;
        rep(i , 0 , n - 1) {
            Union(A[i] , B[i]);
        }

        rep(i , 0 , S.length() - 1) {
            S[i] = (char)(find(S[i]));
        }

        return S;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
