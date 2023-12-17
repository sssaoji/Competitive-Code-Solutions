class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long maxe = *max_element(piles.begin(),piles.end());
        long long i=1;
        long long ans=INT_MAX;
        while(i<=maxe)
        {
            long long mid = (i+maxe)/2;
            long long time = check(piles, mid);
            if(time<=h)
            {
                ans = min(ans, mid);
                maxe = mid-1;
            }
            else if(time>h)
            {
                i = mid+1;
            }
        }
        return ans;
    }
    long long check(vector<int>& piles, long long mid)
    {
        long long hrs = 0;
        for(long long i:piles)
        {
            hrs+=ceil(double(i)/mid);
        }
        return hrs;
    }
};