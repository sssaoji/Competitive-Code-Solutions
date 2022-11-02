class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        map<char, int> mp;
        int j = 0;
        int cnt = 0;
        int mx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]] += 1;
                mx++;
            }
            else
            {
                mp.insert({s[i], 1});
                mx++;
            }
            if (mp.size() == k)
            {
                cnt = max(cnt, mx);
            }
            if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[s[j]] -= 1;
                    if (mp[s[j]] == 0)
                    {
                        mp.erase(s[j]);
                    }
                    mx--;
                    j++;
                }
            }
        }
        return cnt > 0 ? cnt : -1;
    }
};