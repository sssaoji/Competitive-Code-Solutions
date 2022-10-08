#include <bits/stdc++.h>
using namespace std;
class Soln
{
public:
    int kadane(vector<int> &nums)
    {
        int temp = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp = max(nums[i], temp + nums[i]);
            ans = max(ans, temp);
        }
        return ans;
    }
};
int main()
{
    int size, a, z;
    vector<int> arr;
    Soln obj;
    cout << "Enter array size\n";
    cin >> size;
    cout << "Enter array\n";
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    z = obj.kadane(arr);
    cout << z;
}