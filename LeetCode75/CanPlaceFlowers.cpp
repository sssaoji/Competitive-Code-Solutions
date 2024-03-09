class Solution {
public:
    bool canPlaceFlowers(vector<int>& fbd, int n) {
        int cnt=0;
        fbd.insert(fbd.begin(),0);
        fbd.push_back(0);
        for(int i=1;i<fbd.size()-1;i++)
        {
            if(fbd[i]==1)
            {
                cnt++;
            }
            else if(fbd[i]==0)
            {
                if(fbd[i+1]!=0||fbd[i-1]!=0)
                {
                    cnt++;
                }
                if(fbd[i-1]==0&&fbd[i+1]==0)
                {
                    fbd[i]=1;
                }
            }
        }
        return fbd.size()-2-cnt>=n?true:false;
    }
};