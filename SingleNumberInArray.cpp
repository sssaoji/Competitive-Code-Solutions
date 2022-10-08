#include <bits/stdc++.h>
using namespace std;
class Soln
{
public:
    int singleNumber(vector<int> &nums)
    {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            num = num ^ nums[i];
        }
        return num;
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
    z = obj.singleNumber(arr);
    cout << z;
}