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

class FreqStack {
public:
    int maxi = 0;
    unordered_map < int , int > a;
    unordered_map < int , stack < int > > ans;
    FreqStack() {
    }
    
    void push(int x) {
        maxi = max(maxi , ++a[x]);
        ans[a[x]].push(x);
    }
    
    int pop() {
        if(ans[maxi].size() == 0) return NULL;
        int x = ans[maxi].top();
        ans[maxi].pop();
        a[x]--;
        if(ans[maxi].size() == 0) maxi--;
        //cout << maxi << endl;
        return x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
