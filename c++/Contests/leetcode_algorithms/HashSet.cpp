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

class MyHashSet {
public:
    const int MOD = 123456;
    int a[MOD];
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }

    int hash(int x) {
        int index = 0;
        rep(i , 1 , 31) {
            index += (ll)x * ((ll)pow(31 , i) % MOD);
            index %= MOD;
        }
        return index;
    }
    
    void add(int key) {
        int sum = hash(key);

    }
    
    void remove(int key) {
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
