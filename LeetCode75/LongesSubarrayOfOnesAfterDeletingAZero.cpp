class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        int k=1;
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                k--;
            }
            if(k>=0)
            {
                ans = max(ans, j-i+1);
            }
            else if(k<0)
            {
                while(k<0)
                {
                    if(nums[i]==0)
                    {
                        k++;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans-1;
    }
};