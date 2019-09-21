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
    string removeKCharacters(string a , int k) {
        int n = a.length();
        stack < pair < char , int > > s;

        rep(i , 0 , n - 1) {
            int num = 1;

            if(s.empty()) {
                s.push({a[i] , 1});
                continue;
            }
            pair < char , int > temp = s.top();
            if(temp.first == a[i]) {
                s.push({a[i] , temp.second + 1});
            //    cout << first[i] << " added " << temp.second + 1 << endl;
            }
            else {
                s.push({a[i] , 1});
             //   cout << first[i] << " " << 1 << endl;
            }

            temp = s.top();

            if(temp.second == k) {
               // cout << temp.first << " " << temp.second << endl;
                while(!s.empty() && s.top().first == temp.first) {
                    s.pop();
                }
            }
        }

        string ans = "";

        while(!s.empty()) {
            ans += s.top().first;
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    Solution s;

    int k = 2;
    cout << s.removeKCharacters("aaaabbc" , k) << endl; 
    return 0;
}
