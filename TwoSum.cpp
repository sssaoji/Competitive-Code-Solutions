#include <algorithm>
#include "iostream"
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> arr;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.find(target - nums[i]) != umap.end())
            {
                arr.push_back(i);
                arr.push_back(umap[target - nums[i]]);
                return arr;
            }
            umap.insert({nums[i], i});
        }
        return arr;
    }
};
int main()
{
    vector<int> arr, abc;
    int size, target;
    Solution obj;
    cout << "Enter array size\n";
    cin >> size;
    cout << "Enter vector\n";
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << "Enter target value\n";
    cin >> target;
    abc = obj.twoSum(arr, target);
    for (int i = 0; i < abc.size(); i++)
    {
        cout << abc[i] << " ";
    }
}