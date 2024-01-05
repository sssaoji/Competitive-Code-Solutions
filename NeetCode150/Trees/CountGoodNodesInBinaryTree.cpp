/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int soln(TreeNode* root, int mx)
    {
        int ans=0;
        if(root==NULL)
        {
            return 0;
        }
        if(root->val>=mx)
        {
            ans=1;
        }
        mx = max(mx, root->val);
        return ans+soln(root->left, mx) + soln(root->right, mx);
    }
    int goodNodes(TreeNode* root) {
        return soln(root, root->val);
    }
};