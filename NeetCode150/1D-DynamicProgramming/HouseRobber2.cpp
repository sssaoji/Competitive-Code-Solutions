class Solution {
public:
    int soln(vector<int>& nums, int end, int ind, vector<int>&arr)
    {
        if(ind>=end)
        {
            return 0;
        }
        if(arr[ind]!=-1)
        {
            return arr[ind];
        }
        return arr[ind]=max(nums[ind]+soln(nums,end,ind+2, arr), soln(nums, end, ind+1, arr));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int>arr(101, -1);
        vector<int>arr1(101, -1);
        int ans = max(soln(nums, nums.size()-1, 0,arr), soln(nums,nums.size(), 1, arr1));
        return ans;
    }
};