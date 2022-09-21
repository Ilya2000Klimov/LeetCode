class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int size = nums.size();
        
        if (size == 0) return 0;
        
        int ans = 0;
        
        unordered_map <int,int> map;
        
        int sum = 0;
        
        map[0]++;
        
        for(int i = 0; i < size; i++)
        {
            sum += nums[i];
            
            ans += map[sum-k];
            
            map[sum]++;
        }
        
        return ans;
        
    }
};