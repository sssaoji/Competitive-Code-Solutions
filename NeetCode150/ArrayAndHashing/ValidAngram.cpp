class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        map<char,int>mp,up;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            up[t[i]]++;
        }
        if(mp==up)
        {
            return true;
        }
        return false;
    }
};