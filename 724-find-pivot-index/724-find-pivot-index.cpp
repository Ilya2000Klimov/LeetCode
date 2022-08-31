class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int lSum = 0;
        int rSum = std::accumulate(nums.begin() + 1, nums.end(), 0);
        
        int i = 0;
        for (; lSum != rSum;)
        {
            i++;
            
            if (i < nums.size())
                lSum += nums[i-1];
            else
                return -1;
            rSum -=nums[i];
        }
        return i;
    }
};