#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 1534567;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

int a[N];
int n;
int temp[N];

int merge(int l , int mid , int r) {
    int i , j , k;
    i = l;
    j = mid;
    k = l;
    int inv = 0;
    while(i <= mid - 1 && j <= r) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            inv = inv + (mid - i);
        }
    }

    while(i <= mid - 1) {
        temp[k++] = a[i++];
    }

    while(j <= r) {
        temp[k++] = a[j++];
    }

    rep(i , l , r) {
        a[i] = temp[i];
    }

    return inv;
}
int mergeSort(int l , int r) {
    int cnt = 0;
    if(r > l) {
        int mid = (l + r) / 2;
        cnt += mergeSort(l , mid);
        cnt += mergeSort(mid + 1 , r);
        cnt += merge(l , mid + 1 , r);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n;

    rep(i , 1 , n) cin >> a[i];

    cout << mergeSort(1 , n) << endl;

    return 0;
}
