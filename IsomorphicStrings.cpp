class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> mp;
        map<char, char> mp1;
        int a = 1;
        int b = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                if (mp[s[i]] != t[i])
                {
                    a = 0;
                }
            }
            else
            {
                mp.insert({s[i], t[i]});
            }
            if (mp1.find(t[i]) != mp1.end())
            {
                if (mp1[t[i]] != s[i])
                {
                    b = 0;
                }
            }
            else
            {
                mp1.insert({t[i], s[i]});
            }
        }
        return a & b;
    }
};