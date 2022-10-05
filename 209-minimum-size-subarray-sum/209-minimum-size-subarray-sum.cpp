class Solution{
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums)
//     {
//         int minLength = 2147483647;
//         int sum = 0;
//         for(int trail = 0, lead = 0; lead < nums.size(); lead++)
//         {
//             sum += nums[lead];
//             if (sum >=target)
//             {
//                 minLength = std::min(minLength, (lead - trail + 1));
//                 sum -= nums[trail];
//                 trail++;
//             }
            
//         }
        
//         return minLength;
//     }
// };