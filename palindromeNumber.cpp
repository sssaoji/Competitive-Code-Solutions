class Solution
{
public:
    bool isPalindrome(int x)
    {
        string a;
        a = to_string(x);
        cout << a;
        int len = a.length();
        int i = 0;
        int j = len - 1;
        while (i <= j)
        {
            if (a[i] != a[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};