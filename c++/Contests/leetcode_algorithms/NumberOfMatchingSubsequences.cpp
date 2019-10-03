#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    bool check(string a, string b) {
      int j = 0;
      int m = a.length();
      int n = b.length();
      if(a.length() > b.length()) return false;
      rep(i , 0 , n - 1) {
        if(b[i] == a[j]) {
          j++;
        }
        if(j == m) return true;
      }

      return (j == m);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector < vector < int > > a(26);
        int n = s.length();

        rep(i , 0 , n - 1) {
          a[s[i] - 'a'].push_back(i);
        }
        int res = 0;
        for(auto j: words) {
          bool found = true;
          int x = -1;
          for(char c : j) {
            auto it = upper_bound (a[c - 'a'].begin(), a[c - 'a'].end(), x);
            if (it == a[c - 'a'].end()) found = false;
            else x = *it;
          }

          if(found) {
            res++;
            cout << j << endl;
          }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
