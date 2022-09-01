class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int sum = 0;
        vector<int> result = vector<int> {};
        
        
        for (auto &n : nums)
        {
            if (n % 2 == 0) sum += n;
        }
        
        for (auto &q : queries)
        {
            if (nums[q[1]] % 2 == 0) sum -= nums[q[1]];
            
            nums[q[1]] += q[0];
            
            if (nums[q[1]] % 2 == 0) sum += nums[q[1]];
            
            result.push_back(sum);
        }
            
        
        return(result);
    }
};