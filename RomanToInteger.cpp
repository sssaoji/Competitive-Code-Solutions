class Solution
{
public:
    int romanToInt(string s)
    {
        int val = 0;
        unordered_map<char, int> umap;
        umap.insert({'I', 1});
        umap.insert({'V', 5});
        umap.insert({'X', 10});
        umap.insert({'L', 50});
        umap.insert({'C', 100});
        umap.insert({'D', 500});
        umap.insert({'M', 1000});
        for (int i = 0; i < s.size(); i++)
        {
            if (umap[s[i]] < umap[s[i + 1]])
            {
                val = val + (umap[s[i + 1]] - umap[s[i]]);
                i++;
            }
            else
            {
                val = val + umap[s[i]];
            }
            cout << val << " ";
        }
        return val;
    }
};