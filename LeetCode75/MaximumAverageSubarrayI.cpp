class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double tot=0;
        double ans=INT_MIN;
        while(j<nums.size())
        {
            tot+=nums[j];
            if(j-i+1==k)
            {
                ans = max(ans, tot/k);
                tot-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};