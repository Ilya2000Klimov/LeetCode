class Solution {
public:
    char checkBomb(vector<vector<char>>& board, vector<int> click)
    {
        vector <int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector <int> y = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        board[click[0]][click[1]] = '0';
        for(int i = 0; i < x.size(); i++)
        {
            if(click[0] + x[i] >= 0 && click[0] + x[i] < board.size() && click[1] + y[i] >= 0 && click[1] + y [i] < board[0].size() && board[click[0] + x[i]][click[1] + y[i]] == 'M')
            {
                board[click[0]][click[1]] = board[click[0]][click[1]] + 1;
            }
        }
        
        if (board[click[0]][click[1]] == '0')
            board[click[0]][click[1]] = 'B';
        return board[click[0]][click[1]];
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        if(board[click[0]][click[1]] == 'B')
            return board;
        
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        
        
        queue<vector<int>> q;
        q.push(click);
        vector<int> temp;
        
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            
            if(temp[0] < 0 || temp[0] >= board.size() || temp[1] < 0 || temp[1] >= board[0].size() || board[temp[0]][temp[1]] == 'B' || board[temp[0]][temp[1]] == '1' || board[temp[0]][temp[1]] == '2' || board[temp[0]][temp[1]] == '3' || board[temp[0]][temp[1]] == '4' || board[temp[0]][temp[1]] == '5' || board[temp[0]][temp[1]] == '6' || board[temp[0]][temp[1]] == '7' || board[temp[0]][temp[1]] == '8')
                ;
            else if(board[temp[0]][temp[1]] == 'E')
                if (checkBomb(board, temp) == 'B')
                {
                    q.push({temp[0]-1, temp[1]-1});
                    q.push({temp[0]-1, temp[1]});
                    q.push({temp[0]-1, temp[1]+1});
                    q.push({temp[0], temp[1]-1});
                    q.push({temp[0], temp[1]+1});
                    q.push({temp[0]+1, temp[1]-1});
                    q.push({temp[0]+1, temp[1]});
                    q.push({temp[0]+1, temp[1]+1});
                }
        }
        
        return board;
        
    }
};