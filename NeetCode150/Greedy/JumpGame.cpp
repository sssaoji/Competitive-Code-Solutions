class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size()-1;
        // int cnt=nums[0];
        // int ind = 0;
        // while(cnt>=0)
        // {
        //     cnt = max(cnt, nums[ind]);
        //     if(ind==target)
        //     {
        //         return true;
        //     }
        //     cnt--;
        //     ind++;
        // }

        for (int i=target-1;i>=0;i--)
        {
            if(nums[i]+i>=target)
            {
                target=i;
            }
        }
        return target==0?true:false;
    }
};