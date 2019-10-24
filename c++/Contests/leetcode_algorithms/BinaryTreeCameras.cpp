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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct res {
	int sub;
	int covCamera;
	int covNoCamera;
	res(int a , int b , int c) {
		sub = a;
		covCamera = b;
		covNoCamera = c;
	}
};
class Solution {
public:
    res solve(TreeNode * root) {
        if(root == NULL) {
        	return res(0 , 99999 , 0);
        }
        res lef = solve(root -> left);
        res rig = solve(root -> right);
        int a = min(rig.covNoCamera , rig.covCamera);
        int b = min(lef.covCamera , lef.covNoCamera);
        int sub = lef.covNoCamera + rig.covNoCamera;
        int covNoCamera = min(lef.covCamera + a , rig.covCamera + b);
        int covCamera = 1 + min(lef.sub , b) +  min(rig.sub , a);
        return res(sub , covCamera , covNoCamera);
        
    }
    int minCameraCover(TreeNode* root) {
        res ans = solve(root);
    	return min(ans.covNoCamera , ans.covCamera);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
