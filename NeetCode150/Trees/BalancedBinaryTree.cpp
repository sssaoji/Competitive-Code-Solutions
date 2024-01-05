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
    int cnt=0;
    int calculate(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = calculate(root->left);
        int right = calculate(root->right);
        cnt = max(cnt, abs(right-left));
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        int a = calculate(root);
        return cnt>1?false:true;
    }
};