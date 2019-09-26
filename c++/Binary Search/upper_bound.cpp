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

// for array
int upper_bound(ll a[] , ll n , ll value) {
  if(value >= a[n - 1]) return n;
  int l = 0;
  int r = n - 1;

  while(l < r) {
      const int mid = (l + r) / 2;
      if(value < a[mid]) {
          r = mid;
      }
      else {
          l = mid + 1;
      }
  }

  return l;
}

// for vector
int upper_bound(vector < ll > a , ll value) {
  int n = a.size();
  if(value >= a[n - 1]) return n;
  int l = 0;
  int r = n - 1;

  while(l < r) {
      const int mid = (l + r) / 2;
      if(value < a[mid]) {
          r = mid;
      }
      else {
          l = mid + 1;
      }
  }

  return l;
}

// for double array
int upper_bound(ld a[] , ll n , ld value) {
  if(value >= a[n - 1]) return n;
  int l = 0;
  int r = n - 1;

  while(l < r) {
      const int mid = (l + r) / 2;
      if(value < a[mid]) {
          r = mid;
      }
      else {
          l = mid + 1;
      }
  }

  return l;
}

// for double vector
int upper_bound(vector < ld > a , ld value) {
  int n = a.size();
  if(value >= a[n - 1]) return n;
  int l = 0;
  int r = n - 1;

  while(l < r) {
      const int mid = (l + r) / 2;
      if(value < a[mid]) {
          r = mid;
      }
      else {
          l = mid + 1;
      }
  }

  return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    return 0;
}
