class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int j = num.size()-1;
        int i = 0;
        vector<int>ans;
        while(j>i)
        {
            if(num[i]+num[j]==target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
            }
            if(num[i]+num[j]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};