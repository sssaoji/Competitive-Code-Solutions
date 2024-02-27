class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto mx = *max_element(candies.begin(), candies.end());
        vector<bool>ans(candies.size(),false);
        for(int i=0;i<candies.size();i++)
        {
            if(extraCandies+candies[i]>=mx)
            {
                ans[i]=true;
            }
        }
        return ans;
    }
};