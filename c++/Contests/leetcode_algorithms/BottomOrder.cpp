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
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int n = 0;
    vector < int > ans[123456];
    void dfs(TreeNode * root , int k) {
        if(root == NULL) return ;
        ans[k].push_back(root -> val);
        n = max(n , k);
       // cout << k << endl;
        dfs(root -> left , k + 1);
        dfs(root -> right , k + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector < vector < int > > res;
        if(root == NULL) return res;
        dfs(root , 0);
        rep(i , 0 , n) {
            res.push_back(ans[i]);
        }
        return res;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector < vector < int > > ans = levelOrder(root);
        reverse(ans.begin() , ans.end());
        return ans;
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
