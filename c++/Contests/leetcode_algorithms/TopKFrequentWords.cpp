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

bool comp(pair < int , string > a , pair < int , string > b) {
    if(a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& a, int k) {
        int n = a.size();
        vector < string > A;

        map < string , int > ans;

        for(auto j : a) {
            ans[j]++;
        }

        vector < pair < int , string > > res;
        for(auto j : ans) {
            res.push_back({j.second , j.first});
        }

        sort(res.begin() , res.end() , comp);

        rep(i , 0 , k - 1) {
            A.push_back(res[i].second);
        }

        //sort(A.begin() , A.end());
        return A;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    return 0;
}
