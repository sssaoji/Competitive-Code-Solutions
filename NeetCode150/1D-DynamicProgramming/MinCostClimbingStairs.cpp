class Solution {
public:
    vector<int>arr;
    Solution()
    {
        arr.resize(1001,0);
    }
    int ans(int i, vector<int>& cost)
    {
        if(i>=cost.size())
        {
            return 0;
        }
        if(arr[i]!=0)
        {
            return arr[i];
        }
        return arr[i]=min(cost[i]+ans(i+1, cost), cost[i]+ans(i+2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(ans(0, cost), ans(1,cost));
    }
};