#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 1534567;
const long long mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    void wiggleSort(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector < int > b = a;
        int index = 1;
        per(i , n - 1 , 0) {
            if(index >= n) break;
            a[index] = b[i];
            index += 2;
        }
        index = 0;
        per(i , (n - 1) / 2 , 0) {
            if(index >= n) break;
            a[index] = b[i];
            index += 2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
