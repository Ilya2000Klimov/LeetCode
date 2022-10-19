class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int length = dungeon.size();
        int width = dungeon[0].size();
        
        
        vector<vector<int> > hp(length + 1, vector<int>(width + 1, INT_MAX));
        hp[length][width - 1] = 1;
        hp[length - 1][width] = 1;
        for (int i = length - 1; i >= 0; i--) {
            for (int j = width - 1; j >= 0; j--) {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};