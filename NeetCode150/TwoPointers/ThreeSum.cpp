class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        int j=1;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            j=i+1;
            int k = nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    j++;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                    while(k>j && nums[k]==nums[k-1])
                    {
                        k--;
                    }
                }
                else if(nums[i]+nums[j]+nums[k]<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        return ans;
    }
};