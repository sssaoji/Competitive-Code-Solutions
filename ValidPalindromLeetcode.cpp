class Solution
{
public:
    bool isPalindrome(string s)
    {
        stack<char> st, st1;
        string s1 = "";
        string s2 = "";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                st.push(s[i]);
                s2 += s[i];
            }
        }
        while (st.size())
        {
            s1 += st.top();
            st.pop();
        }
        cout << s1 << " " << s2;
        if (s2 == s1)
        {
            return true;
        }
        return false;
    }
};