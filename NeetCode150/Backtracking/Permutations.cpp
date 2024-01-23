class Solution {
    vector<vector<int>>ans;
    map<int,int>vstd;
public:
    void soln(vector<int>&nums, vector<int>pasd)
    {
        if(pasd.size()==nums.size())
        {
            ans.push_back(pasd);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vstd[nums[i]]==0)
            {
                pasd.push_back(nums[i]);
                vstd[nums[i]]=1;
                soln(nums, pasd);
                pasd.pop_back();
                vstd[nums[i]]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>>ans;
        // sort(nums.begin(), nums.end());
        // ans.push_back(nums);
        // while(next_permutation(nums.begin(), nums.end()))
        // {
        //     vector<int>temp;
        //     for(int i: nums)
        //     {
        //         temp.push_back(i);
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        vector<int>pasd;
        soln(nums, pasd);
        return ans;
    }
};