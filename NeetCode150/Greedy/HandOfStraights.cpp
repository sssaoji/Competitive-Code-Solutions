class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        if(hand.size()%groupSize!=0)
        {
            return false;
        }
        for(int i: hand)
        {
            mp[i]++;
        }
        while(mp.size())
        {
            auto fst = mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp.find(fst+i)==mp.end())
                {
                    return false;
                }
                else
                {
                    mp[fst+i]--;
                    if(mp[fst+i]==0)
                    {
                        mp.erase(fst+i);
                    }
                }
            }
        }
        return true;
    }
};