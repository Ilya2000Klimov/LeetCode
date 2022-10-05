class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int result=0, leftR=-1, rightR=-1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]>right) leftR=i;
            if (nums[i]>=left) rightR=i;
            result+=rightR-leftR;
        }
        return result;
        
    }
};