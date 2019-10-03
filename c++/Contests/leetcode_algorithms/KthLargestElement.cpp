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

class KthLargest {
public:
    priority_queue < int , vector < int > , 
    greater < int > > a;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for(auto j : nums) a.push(j);
        this -> k = k;
    }
    
    int add(int val) {
        // priority_queue < int , vector < int > , 
        // greater < int > > b = a;
        // while(!b.empty()) {
        //     cout << b.top() << " ";
        //     b.pop();
        // }
        // cout << endl;
        
        a.push(val);
        while(a.size() > k) {
            a.pop();
        }
        return a.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
