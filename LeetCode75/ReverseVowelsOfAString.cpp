class Solution {
public:
    bool isVowel(char a)
    {
        a=tolower(a);
        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(j>i)
        {
            if(isVowel(s[i])&&isVowel(s[j]))
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                j--;
                i++;
            }
            else if(isVowel(s[i]))
            {
                j--;
            }
            else if(isVowel(s[j]))
            {
                i++;
            }
            else
            {
                j--;
                i++;
            }
        }
        return s;
    }
};