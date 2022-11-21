class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int x = s1.length();
        int y = s2.length();
        int mx[x + 1][y + 1];
        for (int i = 0; i < x + 1; i++)
        {
            for (int j = 0; j < y + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    mx[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    mx[i][j] = 1 + mx[i - 1][j - 1];
                }
                else
                {
                    mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]);
                }
            }
        }
        int i = x;
        int j = y;
        string s = "";
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                s += s1[i - 1];
                i--;
                j--;
            }
            else
            {
                if (mx[i][j - 1] >= mx[i - 1][j])
                {
                    s += s2[j - 1];
                    j--;
                }
                else
                {
                    s += s1[i - 1];
                    i--;
                }
            }
        }
        if (j > 0 && i == 0)
        {
            while (j != 0)
            {
                s += s2[j - 1];
                j--;
            }
        }
        else if (i > 0 && j == 0)
        {
            while (i != 0)
            {
                s += s1[i - 1];
                i--;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};