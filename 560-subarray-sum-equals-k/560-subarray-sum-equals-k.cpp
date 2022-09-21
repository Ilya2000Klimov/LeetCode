class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        /*vector <int> prefixSum(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        
        */
        int ans = 0;
        
        unordered_map <int,int> map;
        
        int sum = 0;
        
        map[0]++;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            ans += map[sum-k];
            
            map[sum]++;
            
        }
        
        return ans;
        
    }
};