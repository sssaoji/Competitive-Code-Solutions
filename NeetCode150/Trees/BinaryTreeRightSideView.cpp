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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        queue<TreeNode*>q;
        q.push(curr);
        while(q.size())
        {
            int lvl = q.size();
            for(int i=0;i<lvl;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp)
                {
                    if(i==lvl-1)
                    {
                        ans.push_back(temp->val);
                    }
                    if(temp->left)
                    {
                        q.push(temp->left);
                    }
                    if(temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
        }
        return ans;
    }
};