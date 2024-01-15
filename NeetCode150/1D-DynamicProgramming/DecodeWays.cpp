class Solution {
public:
    int soln(string s, int i, vector<int>&arr)
    {
        if(i>s.length()||s[i]=='0')
        {
            return 0;
        }
        if(i==s.length())
        {
            return 1;
        }
        if(arr[i]!=-1)
        {
            return arr[i];
        }
        int way = soln(s, i+1, arr);
        if(stoi(s.substr(i,2))>=10&&stoi(s.substr(i,2))<27)
        {
            way+=soln(s,i+2,arr);
        }
        arr[i]=way;
        return way;
    }
    int numDecodings(string s) {
        vector<int>arr(s.length()+1,-1);
        return soln(s, 0, arr);
    }
};