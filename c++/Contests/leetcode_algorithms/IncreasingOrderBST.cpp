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
	vector < int > a;
    void inorder(TreeNode* root) {
    	if(root == NULL) return ;
    	inorder(root -> left);
    	a.push_back(root -> val);
    	inorder(root -> right);
    } 
    TreeNode* increasingBST(TreeNode* root) {
		 inorder(root);
		 if(a.size() == 0) return NULL;
		 TreeNode * prev = new TreeNode(a[0]);
		 TreeNode * ans = prev;
		 rep(i , 1 , a.size() - 1) {
		 	prev -> right = new TreeNode(a[i]);
		 	prev = prev -> right;
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
