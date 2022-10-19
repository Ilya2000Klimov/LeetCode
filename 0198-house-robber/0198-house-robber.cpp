class Solution {
public:
    int rob(vector<int>& nums)
    {
        int stash1 = 0;
        int stash2 = 0;
        int temp = 0;
        //vector <int> results(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            temp = stash1;
            stash1 = max(stash2 + nums[i], stash1);
            stash2 = temp;
        }
        
        return stash1;
    }
};