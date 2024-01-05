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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        while(q.size())
        {
            int lvl = q.size();
            vector<int>temp;
            for(int i=0;i<lvl;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr)
                {
                    temp.push_back(curr->val);
                    if(curr->left)
                    {
                        q.push(curr->left);
                    }
                    if(curr->right)
                    {
                        q.push(curr->right);
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};