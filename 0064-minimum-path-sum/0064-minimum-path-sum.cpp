class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int length = grid.size() + 1;
        int width = grid[0].size() + 1;
        vector<vector<int>> sum (length, vector<int>(width, INT_MAX));
        
        sum[0][1] = 0;
        sum[1][0] = 0;
        
        for(int i = 1; i < length; i++)
        {
            for(int j = 1; j < width; j++)
            {
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i - 1][j - 1];
            }
        }
        
        return sum[length - 1][width - 1];
        
    }
};