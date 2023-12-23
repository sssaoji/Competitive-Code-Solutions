class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<string,int>mp;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' )
                {
                    string col = "col_" + to_string(i) + "_" + board[i][j];
                    string mix = "mix_" + to_string(i/3) + "_" + to_string(j/3) + "_" + board[i][j];
                    cout<<col<<" "<<mix<<" ";
                    if(mp.find(col)!=mp.end())
                    {
                        return false;
                    }
                    else
                    {
                        mp.insert({col,1});
                    }
                    if(mp.find(mix)!=mp.end())
                    {
                        return false;
                    }
                    else
                    {
                        mp.insert({mix,1});
                    }
                }
                if(board[j][i]!='.')
                {
                    string row = "row_" + to_string(i) + "_" + board[j][i];
                    cout<<row<<"\n";
                    if(mp.find(row)!=mp.end())
                    {
                        return false;
                    }
                    else
                    {
                        mp.insert({row,1});
                    }
                }
            }
        }
        return true;
    }
};