class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        while(j<nums.size()&&i<nums.size())
        {
            if(nums[j]!=0&&nums[i]==0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            }
            else if(nums[i]!=0&&nums[j]!=0)
            {
                i++;
                j++;
            }
            else if(nums[i]!=0)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
};