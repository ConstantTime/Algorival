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

int a[N];
int seg[4 * N];
int combine(int a, int b) {
    return a + b;
}
void build(int t, int i, int j) {
    if (i == j) {
        seg[t] = a[i];
        return ;
    }
    int mid = (i + j) / 2;
    build(t * 2, i, mid);
    build(t * 2 + 1, mid + 1, j);
    seg[t] = combine(seg[2*t], seg[2*t+1]);
}
void updatee(int t, int i, int j, int x, int y) {
    if (i == j) {
        seg[t] = y;
        return ;
    }
    int mid = (i + j) / 2;
    if(x <= mid)    
        updatee(t * 2, i, mid, x, y);
    else
        updatee(t * 2 + 1, mid + 1, j, x, y);
    seg[t] = combine(seg[2*t], seg[2*t+1]);
}
int query(int t, int i, int j, int l, int r) {
    if (l <= i && j <= r) {
        return seg[t];
    }
    int mid = (i + j) / 2;
    if (l <= mid) {
        if (r <= mid) {
            return query(t * 2, i, mid, l, r);
        }
        else {
            int a = query(t * 2, i, mid, l, r);
            int b = query(t * 2 + 1,  mid + 1, j, l, r);
            return combine(a, b);
        }
    }
    else {
        return query(t * 2 + 1,  mid + 1, j, l, r);
    }
}

class NumArray {
public:
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n != 0) {
            rep(i , 1 , n) a[i] = nums[i - 1];
            build(1 , 1 , n);
        }
    }
    
    void update(int i, int val) {
        i++;
        if(i <= n)  
            updatee(1 , 1 , n , i , val);
    }
    
    int sumRange(int i, int j) {
        i++;
        j++;
        return query(1 , 1 , n , i , j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
