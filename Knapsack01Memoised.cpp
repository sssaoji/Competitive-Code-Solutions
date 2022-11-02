#include <bits/stdc++.h>
using namespace std;

int msd[1001][1001];
int knap(vector<int> wt, vector<int> arr, int w, int size)
{
    if (w == 0 || size == 0)
    {
        return 0;
    }
    if (msd[w][size] != -1)
    {
        return msd[w][size];
    }
    if (wt[size - 1] <= w)
    {
        return msd[w][size] = max(arr[size - 1] + knap(wt, arr, w - wt[size - 1], size - 1), knap(wt, arr, w, size - 1));
    }
    else if (wt[size - 1] > w)
    {
        return msd[w][size] = knap(wt, arr, w, size - 1);
    }
}

int main()
{
    vector<int> wt, arr;
    cout << "enter size\n";
    int size, w, ans;
    cin >> size;
    cout << "Enter weight array\n";
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        wt.push_back(a);
    }
    cout << "Enter array\n";
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << "Enter weight\n";
    cin >> w;
    memset(msd, -1, sizeof(msd));
    ans = knap(wt, arr, w, size);
    cout << ans;
}