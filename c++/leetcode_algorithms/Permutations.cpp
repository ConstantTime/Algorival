#include <bits/stdc++.h>
 
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 153456;
const long long mod = 1e18 + 7;
const long double eps = 1e-6;
const long double pi = 3.1415926535;

void doit(vector < vector < int > > &res, vector < int > &a , 
    int l , int r) {

    if(l == r) {
        res.push_back(a);
        return ;
    }
    rep(i , l , r) {
        swap(a[l] , a[i]);
        doit(res , a , l + 1 , r);
        swap(a[l] , a[i]);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
        vector < vector < int > > ans;
        vector < int > res;
        doit(ans , a , 0 , a.size() - 1);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
