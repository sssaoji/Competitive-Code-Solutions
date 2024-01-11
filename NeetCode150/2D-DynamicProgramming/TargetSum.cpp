class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int tsum = (sum+target)/2;
        if(abs(target)>sum || (target+sum)%2!=0)
        {
            return 0;
        }
        int n = nums.size();
        int dp[n+1][tsum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<tsum+1;j++)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        dp[0][0]=1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<tsum+1;j++)
            {
                if(j-nums[i-1]>=0)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][tsum];
    }
};