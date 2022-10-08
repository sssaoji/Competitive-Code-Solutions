#include <bits/stdc++.h>
using namespace std;
int soln(vector<int>);
int main()
{
    int size, z;
    vector<int> arr;
    cout << "Enter size\n";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    z = soln(arr);
    cout << z;
}

int soln(vector<int> arr)
{
    int size, sum1, sum2;
    size = arr.size();
    sort(arr.begin(), arr.end());
    sum1 = arr[size - 1] * arr[size - 2] * arr[size - 3];
    sum2 = arr[0] * arr[1] * arr[size - 1];
    return (max(sum1, sum2));
}