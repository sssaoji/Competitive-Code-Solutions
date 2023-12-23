class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j=1;
        int i=0;
        int ans=0;
        while(i<j && j<prices.size())
        {
            if(prices[i]<prices[j])
            {
                ans = max(ans, prices[j]-prices[i]);
                j++;
            }
            else if(prices[i]>=prices[j])
            {
                i=j;
                j++;
            }
        }
        return ans;

    }
};