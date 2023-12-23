class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int siz = nums.size();
        int pre[siz];
        int pst[siz];
        pre[0]=nums[0];
        pst[siz-1]=nums[siz-1];
        for(int i=1;i<siz;i++)
        {
            pre[i] = nums[i]*pre[i-1];
            pst[siz-i-1] = nums[siz-i-1]*pst[siz-i];
        }
        vector<int>ans;
        for(int i=0;i<siz;i++)
        {
            if(i==0)
            {
                ans.push_back(pst[i+1]);
            }
            else if(i==siz-1)
            {
                ans.push_back(pre[i-1]);
            }
            else
            {
                ans.push_back(pst[i+1]*pre[i-1]);
            }
        }
        return ans;
    }
};