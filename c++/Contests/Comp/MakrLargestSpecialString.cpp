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

int n;
void doit(vector < vector < int > > &ans , 
  vector < int > &res , int sum , int total , int i) {

  if(sum == total) {
    ans.push_back(res);
    return ;
  }
  if(i > n || sum > total) return ;
  res.push_back(i);
  doit(ans , res , sum + i , total , i + 1);
  res.pop_back();
  doit(ans , res , sum , total , i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n;

    vector < vector < int > > a;
    vector < int > res;
    int sum = 0;
    int total = (n * (n + 1)) / 2;
    int i = 1;

    doit(a , res , sum , total / 2 , i);

    // for(auto j : a) {
    //   for(auto k : j) {
    //     cout << k << " ";
    //   }
    //   cout << endl;
    // }
    
    cout << a.size() << endl;
    return 0;
}
