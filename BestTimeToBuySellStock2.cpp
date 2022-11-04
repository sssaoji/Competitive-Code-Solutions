class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int cnt = 0;
        int j = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[j])
            {
                cnt += prices[i] - prices[j];
                j = i;
            }
            else if (prices[i] < prices[j])
            {
                j = i;
            }
        }
        return cnt;
    }
};