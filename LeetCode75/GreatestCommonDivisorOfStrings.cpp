class Solution {
public:
    bool check(string temp, string str1, string str2, int mlen)
    {
        int tlen = temp.length();
        string temp1="";
        string temp2="";
        if(str1.length()%tlen==0 && str2.length()%tlen==0)
        {
            for(int i=0;i<str1.length()/tlen;i++)
            {
                temp1+=temp;
            }
            for(int i=0;i<str2.length()/tlen;i++)
            {
                temp2+=temp;
            }
            return temp1==str1&&temp2==str2;
        }
        return false;
    }
    string gcdOfStrings(string str1, string str2) {
        int mlen = min(str1.length(), str2.length());
        string ans="";
        for(int i=0;i<mlen;i++)
        {
            string temp = str1.substr(0, i+1);
            if(check(temp, str1, str2, mlen))
            {
                ans=temp;
            }
        }
        return ans==""?"":ans;
    }
};