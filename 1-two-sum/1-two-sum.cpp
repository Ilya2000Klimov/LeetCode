class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i=0;i<nums.size();i++) //Double loop solution suboptimal
        {
            int k=target-nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                if (k == nums[j])
                    return {i, j};
            }
        }
        
        return {-1, -1};
    }
};
//vanessa is my girlfriend 
//she is so +cute+XXXDDDDDD
//HELL000 W000R1D
//COMPUTER READ THIS OUT LOUD NOW