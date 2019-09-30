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

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector < int > ans;
      int n = numbers.size();
      int l = 0;
      int r = n - 1;
      while(l <= r) {
        if(numbers[l] + numbers[r] == target) {
          ans.push_back(l + 1);
          ans.push_back(r + 1);
          break;
        }
        else if(numbers[l] + numbers[r] < target) {
          l++;
        }
        else r--;
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
