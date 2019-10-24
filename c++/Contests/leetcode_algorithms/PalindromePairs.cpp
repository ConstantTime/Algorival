#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e9 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Solution {
public:
    bool palin(string& s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    unordered_map < string , int > a;
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector < vector < int > > ans;
        rep(i , 0 , n - 1) {
            string key = words[i];
            reverse(key.begin() , key.end());
            a[key] = i;
        }

        if(a.find("") != a.end()) {
            rep(i , 0 , n - 1) {
                if(i == a[""]) continue;
                if(palin(words[i])) {
                    ans.push_back({a[""] , i});
                }
            }
        }

        rep(i , 0 , n - 1) {

            for(int j = 0 ; j < words[i].length() ; j++){
              //  cout << j << " f" << endl;
                string lef = words[i].substr(0 , j);
                string rig = words[i].substr(j , words[i].size() - j);
                if(a.find(lef) != a.end() && palin(rig) &&
                    a[lef] != i) {
                    ans.push_back({i , a[lef]});
                }
                else if (a.find(rig) != a.end() && palin(lef) && 
                    a[rig] != i) {
                    ans.push_back({a[rig] , i});
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
