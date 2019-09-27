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

bool comp(pair < int , int > a , pair < int , int > b) {
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
class Solution {
public:
    vector < int > MaxFromOneArray(vector < int > a , int k) {
        vector < int > ans;
        int n = a.size();
        if(k == 0 || n == 0) return ans;
        vector < pair < int , int > > res;
        rep(i , 0 , n - 1) {
            res.push_back({a[i] , i});
        }
        sort(res.begin() , res.end() , comp);
        int cnt = k;
        int maxi = -1;
        bool vis[n];
        fill(vis , vis + n , false);
        while(ans.size() != k) {
            bool flag = false;
            int i = 0;
            while(i <= n - 1) {
                if(vis[i] == false && n - 1 - res[i].second >= cnt - 1
                 && res[i].second >= maxi) {
                    cnt--;
                    vis[i] = true;
                    flag = true;
                    ans.push_back(res[i].first);
                    maxi = res[i].second;
                    break;
                }
                i++;
            }
            if(flag == false) break;
        }
        return ans;
    }
    vector < int > merge(vector < int > a , vector < int > b) {
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;
        vector < int > ans;
        if(m == 0) return b;
        if(n == 0) return a;
        while(i < m && j < n) {
            if(a[i] >= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
        if(i != m) {
            rep(k , i , m - 1) {
                ans.push_back(a[k]);
            }
        }
        if(j != n) {
            rep(k , j , n - 1) {
                ans.push_back(b[k]);
            }
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        vector < vector < int > > ans;

        rep(i , 0 , k) {
            vector < int > res;
            vector < int > A = MaxFromOneArray(a , i);
            vector < int > B = MaxFromOneArray(b , k - i);
            
            if(A.size() + B.size() == k) {
                res = merge(A , B);
                ans.push_back(res);
                cout << i << " iiiii " << endl;
                for(auto j : A) {
                    cout << j << " ";
                }
                cout << endl;
                for(auto j : B) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
        sort(ans.begin() , ans.end());
        if(ans.size() == 0) {
            vector < int > res;
            return res;
        }
        return ans[ans.size() - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
