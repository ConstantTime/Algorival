#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      int n = people.size();
      int l = 0;
      int r = n - 1;
      int cnt = 0;
      int num = 0;
      sort(people.begin(), people.end());
      while(cnt != n && l <= r) {
        if(l == r) {
          num++;
          break;
        }
        if(people[l] + people[r] <= limit) {
          num++;
          cnt += 2;
          l++;
          r--;
        }
        else {
          num++;
          cnt++;
          r--;
        }
      } 
      return num;     
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
