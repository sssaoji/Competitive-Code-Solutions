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
    void countNodes(TreeNode *root, int maxVal)
    {
        if(root==NULL)
        {
            return;
        }
        if(maxVal<=root->val)
        {
            cnt++;
            maxVal=root->val;
        }
        countNodes(root->left, maxVal);
        countNodes(root->right, maxVal);
    }
    int goodNodes(TreeNode* root) {
        countNodes(root, root->val);
        return cnt;
    }
};