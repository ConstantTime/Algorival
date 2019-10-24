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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *lef;
 *     TreeNode *rig;
 *     TreeNode(int x) : val(x), lef(NULL), rig(NULL) {}
 * };
 */
class Solution {
public:
    int maxi;
    int dfs(TreeNode * root) {
        if(root == NULL) return 0;
        int lef = max(0 , dfs(root -> left));
        int rig = max(0 , dfs(root -> right));
        maxi = max(maxi , lef + rig + root -> val);
        return max(lef, rig) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        dfs(root);
        return maxi;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
        
    cin >> a;

    cout << longestPalindrome(a) << endl;

    return 0;
}
