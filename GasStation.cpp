class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> arr, arr1;
        int size = gas.size();
        for (int i = 0; i < gas.size(); i++)
        {
            arr.push_back(gas[i]);
        }
        for (int i = 0; i < gas.size(); i++)
        {
            arr.push_back(gas[i]);
        }
        int j = 0;
        int cnt = 0;
        int total = 0;
        ;
        for (int i = 0; i < arr.size(); i++)
        {
            total += arr[i] - cost[i % size];
            cnt++;
            if (total >= 0 && cnt == gas.size() + 1)
            {
                return j;
            }
            if (total < 0)
            {
                while (total < 0)
                {
                    total -= (arr[j] - cost[j % size]);
                    j++;
                    cnt--;
                }
            }
        }
        return -1;
    }
};