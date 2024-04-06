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
    void traverse(TreeNode* root, vector<int>&temp)
    {
        if(root==NULL)
        {
            return;
        }
        traverse(root->left, temp);
        traverse(root->right, temp);
        if(root->left==NULL&root->right==NULL)
        {
            temp.push_back(root->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a1,a2;
        traverse(root1, a1);
        traverse(root2, a2);
        if(a1==a2)
        {
            return true;
        }
        return false;
    }
};