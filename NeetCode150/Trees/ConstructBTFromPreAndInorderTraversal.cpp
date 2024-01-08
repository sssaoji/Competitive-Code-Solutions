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
    int idx=0;
    map<int,int>mp;
    TreeNode* crt(int st, int end, vector<int>&pre, vector<int>& ino)
    {
        if (idx >= pre.size() || st > end) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[idx]);
        int loc = mp[pre[idx]];
        idx++;
        root->left = crt(st, loc - 1, pre, ino);
        root->right = crt(loc + 1, end, pre, ino);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int left_st = 0;
        int left_end = inorder.size()-1;
        return crt(left_st, left_end, preorder, inorder);
    }
};