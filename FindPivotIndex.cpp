class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        int fin = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            float abc = sum - nums[i];
            if (abc / 2 == fin)
            {
                return i;
            }
            fin += nums[i];
        }
        return -1;
    }
};