//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string Reduced_String(int k, string word)
    {
        // Your code goes here
        stack<pair<char, int>> st;
        st.push(make_pair(word[0], 1));
        if (k == 1 || k == 0)
        {
            return "";
        }
        int i = 1;
        string s = "";
        while (i <= word.length())
        {
            if (st.size() > 0)
            {
                if (st.top().first == word[i] && st.top().second == k - 1)
                {
                    st.pop();
                }
                else if (st.top().first == word[i])
                {
                    int a = st.top().second + 1;
                    st.pop();
                    st.push(make_pair(word[i], a));
                }
                else
                {
                    st.push(make_pair(word[i], 1));
                }
            }
            else
            {
                st.push(make_pair(word[i], 1));
            }
            i++;
        }
        while (st.size())
        {
            int a = st.top().second;
            while (a)
            {
                s += st.top().first;
                a--;
            }
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        Solution obj;
        cout << obj.Reduced_String(k, s) << "\n";
    }

    return 0;
}
// } Driver Code Ends