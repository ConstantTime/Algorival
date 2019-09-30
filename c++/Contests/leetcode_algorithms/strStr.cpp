#include <bits/stdc++.h>
 
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const long long N = 153456;
const long long mod = 1e18 + 7;
const long double eps = 1e-6;
const long double pi = 3.1415926535;

void getZarr(string str, int Z[]) { 
    int n = str.length(); 
    int L, R, k;
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    { 
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L; 
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
} 

int search(string text, string pat) { 
    string concat = pat + "$";
    concat += text;
    int l = concat.length(); 
    int Z[l]; 
    getZarr(concat , Z); 
  
    for (int i = 0; i < l; ++i) { 
        if (Z[i] == pat.length()) {
            cout << i << " " << pat.length() << endl;
            int index = i - pat.length() - 1; 
            return index;
        }
    } 
    return -1;
} 

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == haystack) {
            return 0;
        }
        return search(haystack , needle);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
