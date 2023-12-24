class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0;
        int r=0;
        map<char,int>act, mp;
        for(auto i: s1)
        {
            act[i]++;
        }
        while(r<s2.length())
        {
            mp[s2[r]]++;
            if(r-l+1<s1.length())
            {
                r++;
            }
            else if(r-l+1==s1.length())
            {
                if(mp==act)
                {
                    return true;
                }
                mp[s2[l]]--;
                if(mp[s2[l]]==0)
                {
                    mp.erase(s2[l]);
                }
                l++;
                r++;
            }
        }
        return false;
    }
};