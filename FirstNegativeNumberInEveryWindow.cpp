#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr, fin;
    list<int> temp;
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
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            temp.push_back(arr[i]);
        }
        if (k == i - j + 1)
        {
            if (temp.size() == 0)
            {
                fin.push_back(0);
            }
            else
            {
                fin.push_back(temp.front());
            }
            if (arr[j] == temp.front())
            {
                temp.pop_front();
            }
            j++;
        }
    }
    for (int i = 0; i < fin.size(); i++)
    {
        cout << fin[i];
    }
}