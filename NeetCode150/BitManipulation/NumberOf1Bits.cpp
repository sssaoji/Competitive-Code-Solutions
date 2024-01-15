class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        int i=0;
        while(n)
        {
            // if(n%2==1)
            // {
            //     cnt++;
            // }
            //n=n/2;
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
};