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

void doit(vector < vector < int > > &res , vector < int > &ans , 
    vector < int > a , int index, int k) {

    if(ans.size() == k) {
        res.push_back(ans);
        return ;
    }
    if(index == a.size()) return ;
    rep(i , index , a.size() - 1) {
        ans.push_back(a[i]);
        doit(res , ans , a , i + 1 , k);
        ans.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector < vector < int > > ans;
        vector < int > res;
        vector < int > a;
        rep(i , 1 , n) a.push_back(i);
        doit(ans , res , a , 0 , k);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
