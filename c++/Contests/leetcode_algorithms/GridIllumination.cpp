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
    vector<int> gridIllumination(int n, 
        vector<vector<int>>& a, vector<vector<int>>& queries) {
        
        vector < int > res;

        unordered_map < int , int > A , B , C , D;
        unordered_map < int , unordered_set < int > > ls;

        for(auto k : a) {
            int i = k[0];
            int j = k[1];
            if(ls[i].insert(j).second) {
                A[i]++;
                B[j]++;
                C[i + j]++;
                D[i - j]++;
            }
        }

        for(auto k : queries) {
            int i = k[0];
            int j = k[1];
            if(A[i] || B[j] || C[i + j] || D[i - j]) {
                res.push_back(1);
                rep(I , i - 1 , i + 1) {
                    rep(J , j - 1 , j + 1) {
                        if(ls[I].erase(J)) {
                            A[I]--;
                            B[J]--;
                            C[I + J]--;
                            D[I - J]--;
                        }
                    }
                }
            }
            else {
                res.push_back(0);
            }
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
