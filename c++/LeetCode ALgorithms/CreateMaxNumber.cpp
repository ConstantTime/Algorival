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

bool comp(pair < char , int > a , pair < char , int > b) {
  if(a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}

// TODO - not complete yet
class Solution {
public:
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        int m = a.size();
        int n = b.size();

        vector < int > res;
        vector < int > temp1 , temp2;
        temp1 = a;
        temp2 = b;
        sort(temp1.begin(), temp1.end() , greater < int > ());
        sort(temp2.begin(), temp2.end() , greater < int > ());
        unordered_map < int , int > cnt;

        int i = 0;
        int j = 0;
        int count = 0;
        while(count < k) {
            if(temp1[i] >= temp2[j]) {
                if(i < m) {
                    cnt[temp1[i]]++;
                    i++;
                }
                else {
                    cnt[temp2[j]]++;
                    j++;
                }
            }
            else {
                if(j < n) {
                    cnt[temp2[j]]++;
                    j++;
                }
                else {
                    cnt[temp1[i]]++;
                    i++;
                }   
            }
            count++;
        }

        rep(i , 0 , m - 1) {
            if(cnt.find(a[i]) != cnt.end()) {
                res.push_back(a[i]);
                cnt[a[i]]--;
            }
        }

        rep(i , 0 , n - 1) {
            if(cnt.find(b[i]) != cnt.end() && cnt[b[i]] > 0) {
                res.push_back(b[i]);
            }
        }

        sort(res.begin(), res.end() , greater < int >());

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
