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
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        vector < int > ans;
        unordered_map < string , int > cnt;
        for(string word : words) {
            cnt[word]++;
        }      
        int m = words.size();
        if(n == 0 || m == 0) return ans;
        int len = words[0].length();
        rep(i , 0 , n - m * len) {
            unordered_map < string , int > seen;
            int j = 0;
            for(; j < m ; j++) {
                string word = s.substr(i + j * len, len);
                if (cnt.find(word) != cnt.end()) {
                    seen[word]++;
                    if (seen[word] > cnt[word])
                        break;
                }
                else break;
            }
            if(j == m) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

    return 0;
}
