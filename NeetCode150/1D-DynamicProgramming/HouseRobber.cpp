class Solution {
public:
    vector<int>arr;
    Solution()
    {
        arr.resize(101,-1);
    }
    int ans(int i, vector<int>& nums)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(arr[i]!=-1)
        {
            return arr[i];
        }
        return arr[i]=max(nums[i]+ ans(i+2,nums), ans(i+1,nums));
    }
    int rob(vector<int>& nums) {
        return ans(0,nums);
    }
};