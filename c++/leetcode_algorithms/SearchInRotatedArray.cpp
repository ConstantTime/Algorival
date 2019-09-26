#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 3534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    int binarySearch(vector < int > &a , int l , int r, int target) {
        if(r < l) return -1;
        while(l <= r) {
          int mid = (l + r) / 2;

          if(a[mid] == target) return mid;

          if(target > a[mid]) {
            return binarySearch(a , mid + 1 , r , target);
          }
          return binarySearch(a , l , mid - 1 , target);
        }

        return -1;      
    }
    int findPivot(vector < int > a , int l , int r) {
      if(r < l) return -1;
      if(r == l) return l;

      int mid = (r + l) / 2;

      if(mid < r && a[mid] > a[mid + 1]) {
        return mid;
      }

      if(mid > l && a[mid] < a[mid - 1]) {
        return mid - 1;
      }

      if(a[l] >= a[mid]) {
        return findPivot(a , l , mid - 1);
      }

      return findPivot(a , mid + 1 , r);
    }
    int search(vector<int>& a, int target) {
      int n = a.size();

      if(n == 0) return -1;

      int l = 0;
      int r = n - 1;

      int pivot = findPivot(a , l , r);

      if(pivot == -1) {
        return binarySearch(a , 0 , n - 1, target);
      }
      if(a[pivot] == target) {
        return pivot;
      }

      if(a[0] <= target) {
        return binarySearch(a , 0 , pivot - 1 , target);
      }
      return binarySearch(a , pivot + 1 , n - 1 , target);

    }
};  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
