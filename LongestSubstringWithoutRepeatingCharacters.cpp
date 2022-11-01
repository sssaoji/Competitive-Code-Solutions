class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> mp;
        int j = 0;
        int mx = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                mp.insert({s[i], 1});
                mx++;
            }
            else if (mp.find(s[i]) != mp.end())
            {
                mx++;
                while (s[i] != s[j])
                {
                    if (mp.find(s[j]) != mp.end())
                    {
                        mp.erase(s[j]);
                        mx--;
                    }
                    j++;
                }
                if (s[i] == s[j])
                {
                    mp.erase(s[j]);
                    mp.insert({s[i], 1});
                    j++;
                    mx--;
                }
            }
            ans = max(ans, mx);
        }
        return ans;
    }
};