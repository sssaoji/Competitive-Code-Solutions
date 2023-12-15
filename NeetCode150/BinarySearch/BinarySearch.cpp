class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(j>=i)
        {
            int mid = (j+i)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]<target)
            {
                i = mid;
            }
            else if(nums[mid]>target)
            {
                j=mid;
            }
        }
        return -1;
    }
};