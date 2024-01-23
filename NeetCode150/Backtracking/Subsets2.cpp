class Solution {
    vector<vector<int>>ans;
public:
    void soln(vector<int>&nums, int ind, vector<int>temp)
    {
        if(ind==0)
        {
            if(ans.size()!=0)
            {
                auto i = ans[ans.size()-1];
                if(lexicographical_compare(i.begin(), i.end(), temp.begin(), temp.end()))
                {
                    ans.push_back(temp);
                }
            }
            else
            {
                ans.push_back(temp);
            }
            return;
        }
        soln(nums, ind-1, temp);
        temp.push_back(nums[ind-1]);
        soln(nums, ind-1, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(), nums.end());
        soln(nums, nums.size(), temp);
        return ans;
    }
};