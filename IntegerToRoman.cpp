class Solution
{
public:
    string intToRoman(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hund[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thds[] = {"", "M", "MM", "MMM"};

        string ons = ones[num % 10];
        string tns = tens[(num / 10) % 10];
        string hds = hund[(num / 100) % 10];
        string ths = thds[num / 1000];
        return (ths + hds + tns + ons);
    }
};