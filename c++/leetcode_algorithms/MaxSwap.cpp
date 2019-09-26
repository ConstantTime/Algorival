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

bool comp(pair < char , int > a , pair < char , int > b) {
  if(a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++) { 
          for(int j = i + 1; j < s.size(); j++) {
                if((s[i] - '0') < (s[j] - '0')) {
                    swap(s[i], s[j]);
                    ans = max(ans, stoi(s));
                    swap(s[i], s[j]);
                }
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
