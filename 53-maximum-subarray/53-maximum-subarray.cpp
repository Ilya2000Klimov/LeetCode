//Time complexity O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if (nums.size() == 1) return nums[0];
        
        int max = nums[0];
        int sum = INT_MIN;
        
        for (auto &n : nums)
        {
            if (sum < 0) sum = n;
            else sum += n;
            
            max = std::max(max, sum);
        }
        return (max);
    }
};

//not quite right