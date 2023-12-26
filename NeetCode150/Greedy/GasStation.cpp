class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int l=0;
        int r=0;
        int tot=0;
        int siz = cost.size();
        while(r<siz*2)
        {
            tot+=gas[r%siz]-cost[r%siz];
            if(r-l+1==siz+1 && tot>=0)
            {
                return r%siz;
            }
            if(tot<0)
            {
                while(tot<0)
                {
                    tot-=gas[l%siz]-cost[l%siz];
                    l++;
                }
            }
            r++;
        }
        return -1;
    }
};