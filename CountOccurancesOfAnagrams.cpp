#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr, abc;
    string str, ang;
    map<char, int> mp1, mp2;
    cout << "Enter main string\n";
    cin >> str;
    cout << "Enter ang string\n";
    cin >> ang;
    int cnt = 0;
    int j = 0;
    int ans = 0;
    int k = ang.length();
    for (int i = 0; i < ang.length(); i++)
    {
        if (mp1.find(ang[i]) != mp1.end())
        {
            mp1[ang[i]] += 1;
        }
        else
        {
            mp1.insert({ang[i], 1});
        }
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (mp1.find(str[i]) != mp1.end())
        {
            if (mp2.find(str[i]) != mp2.end())
            {
                mp2[str[i]] += 1;
            }
            else
            {
                mp2.insert({str[i], 1});
            }
        }
        if (k == i - j + 1)
        {
            if (mp1 == mp2)
            {
                ans++;
            }
            if (mp2.find(str[j]) != mp2.end())
            {
                mp2[str[j]] -= 1;
            }
            j++;
        }
    }
    cout << ans;
}