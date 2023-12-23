class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto i: s)
        {
            if(isalpha(i))
            {
                str+=tolower(i);
            }
        }
        cout<<str;
        int i=0;
        int j=str.length()-1;
        while(j>=i)
        {
            if(str[j]!=str[i])
            {
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
};