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
    vector<int>q;
    void mkq(TreeNode* root)
    {
        if(root)
        {
            mkq(root->left);
            q.push_back(root->val);
            mkq(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        mkq(root);
        return q[k-1];
    }
};