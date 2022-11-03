class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mx = 0;
        int j = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] <= prices[j])
            {
                while (prices[i] != prices[j])
                {
                    j++;
                }
            }
            else
            {
                mx = max(mx, prices[i] - prices[j]);
            }
        }
        return mx;
    }
};