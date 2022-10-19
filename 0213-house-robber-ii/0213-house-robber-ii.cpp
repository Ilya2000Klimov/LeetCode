class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        int stash1 = 0;
        int stash2 = 0;
        int stash3 = 0;
        int temp = 0;
        //vector <int> results(nums.size(), 0);
        
        for(int i = 1; i < nums.size(); i++)
        {
            temp = stash1;
            stash1 = max(stash2 + nums[i], stash1);
            stash2 = temp;
        }
        
        stash2 = 0;
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            temp = stash3;
            stash3 = max(stash2 + nums[i], stash3);
            stash2 = temp;
        }
        
        return max(stash1, stash3);
    }
};