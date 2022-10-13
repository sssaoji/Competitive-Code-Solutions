#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr, abc;
    int size, k;
    cout << "Enter array size\n";
    cin >> size;
    cout << "Enter vector\n";
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << "Enter k\n";
    cin >> k;
    int mx = INT_MIN;
    int sum = 0;
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (k == i - j + 1)
        {
            mx = max(mx, sum);
            sum = sum - arr[j];
            j++;
        }
    }
    cout << mx;
}