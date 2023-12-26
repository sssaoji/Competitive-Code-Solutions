class Solution {
public:
    int jump(vector<int>& nums) {
        int target = nums.size()-1;
        int mxval = 0;
        int jmp=0;
        int curr=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            mxval = max(mxval, i+nums[i]);
            if(i==curr)
            {
                jmp++;
                curr = mxval;
            }
        }
        return jmp;
    }
};