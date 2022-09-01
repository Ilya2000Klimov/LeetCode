class Solution {    //O(n) single pass solution
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ans = 0;    //results go here
        int pref = 0;   //the prefix summ
        
        vector<int> remainders(k, 0);
        remainders[pref]++; //add 1 to the prefix summ % == 0, since you dont need the handshake rulle for 0 habndshake rule
        
        for (auto &n : nums)
        {
            pref = (pref + n) % k;
            
            if (pref < 0) pref += k;
            
            ans += remainders[pref]++;
        }
        return ans;
    }
};
