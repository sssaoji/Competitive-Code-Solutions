class Solution {
    vector<vector<int>>ans;
public:
    void soln(vector<int>&nums, int ind, vector<int>arr)
    {
        if(ind==0)
        {
            ans.push_back(arr);
            return;
        }
        soln(nums, ind-1, arr);
        arr.push_back(nums[ind-1]);
        soln(nums, ind-1, arr);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;
        soln(nums, nums.size(), arr);
        return ans;
    }
};