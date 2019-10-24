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

int n, m;
int a[N];
int b[N];

pair < int , pair < int , int > > LIS(int start , int end) {
    bool flag = false;
    rep(i , start , end) {
        if(b[i] != INT_MAX) flag = true;
    }

    if(flag == false || start > end) return {0 , {0 , 0}};

    int len = 1;
    int ans1 = b[start];
    int ans2 = b[start];
    int mini = b[start];
    int maxi = b[start];
    int cnt = 1;
    rep(i , start + 1 , end) {
        if(b[i] > b[i - 1] && b[i] != INT_MAX) {
            cnt++;
        }
        else {
            if(cnt > len) {
                len = cnt;
                ans2 = b[i - 1];
                ans1 = mini;
            }
            cnt = 1;
            mini = b[i];
        }
    }
    if(cnt > len) {
        len = cnt;
        ans2 = b[end];
        ans1 = mini;
    }
    return {len , {ans1 , ans2}};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    cin >> n;

    rep(i , 1 , n) cin >> a[i];

    int maxi = -1;
    rep(i , 1 , n) {
        rep(j , 1 , n) b[j] = a[j];
        pair < int , pair < int , int > > temp = LIS(1 , i);
        int low = temp.second.first;
        int high = temp.second.second;
        int len = temp.first;
        rep(j , i + 1 , n) {
            if(b[j] < low || b[j] > high) continue;
            b[j] = INT_MAX;
        } 
        temp = LIS(i + 1 , n);
        if(len + temp.first > maxi) {
            maxi = len + temp.first;
            cout << i << " .. " << low << " " << high << " maxi - > " << len << ' ' << temp.first << endl;
        } 
    }

    per(i , n , 1) {
        rep(j , 1 , n) b[j] = a[j];
        pair < int , pair < int , int > > temp = LIS(i , n);
        int low = temp.second.first;
        int high = temp.second.second;
        int len = temp.first;
        rep(j , 1 , i - 1) {
            if(b[j] < low || b[j] > high) continue;
            b[j] = INT_MAX;
        } 
        temp = LIS(1 , i - 1);
        if(len + temp.first > maxi) {
            maxi = len + temp.first;
            cout << low << " " << high << " maxiii - > " << len << ' ' << temp.first << endl;
        }    
    }


    cout << maxi << endl;
    return 0;
}
