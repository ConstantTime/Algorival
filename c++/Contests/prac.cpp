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

int lower_bound(int a[] , int n , int value) {
  if(value > a[n - 1]) return n;
  int l = 0;
  int r = n - 1;

  while(l < r) {
      const int mid = (l + r) / 2;
      if(value <= a[mid]) {
          r = mid;
      }
      else {
          l = mid + 1;
      }
  }

  return l;
}

int upper_bound(int a[] , int n , int value) {
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

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    int n;
    cin >> n;
    rep(i , 1 , n) cin >> a[i - 1];

    int q;
    cin >> q;

    sort(a , a + n);
    a[n] = INT_MAX;

    while(q--) {
        int x , k;
        cin >> x >> k;

        rep(i , 0 , n - 1) {
            cout << (a[i] ^ x) << " ";
        }
        cout << endl;
        int b[32];
        per(i , 31 , 0) {
            b[i] = (x & (1 << i)) / ((1 << i));
        } 
        per(i , 31 , 0) {
            b[i] = (1 - b[i]) * pow(2 , i);
        }
        int prev = 0;
        per(i , 31 , 0) {
            b[i] += prev;
            if(b[i] == 0) {
                prev += pow(2 , i);
            }
        }
        per(i , 5 , 1) {
            cout << b[i] << " ";
        }
        cout << endl;   
        per(i , 30 , 0) {
            int low , high;
            low = 0;
            high = pow(2 , i) - 1;
            low += b[i];
            high += b[i];
            int num = 0;
            int l = lower_bound(a , n , low);
            int h = upper_bound(a , n , high);
            if(l == n && h == n) continue;
            int cnt = 0;
            if(a[l] == low && a[h] == high) {
                cnt += h - l + 1;
            }
            else {
                cnt = h - l;
            }
            cout  << low << " " << high << " " << l <<
            " " << h << " " << cnt << endl;
            if(k > cnt) {
                k -= cnt;
            }
        }
    }   
    
    return 0;
}
