class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int max, curr = 0;
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            if(height[i] >= height[j])
                curr = height[j] * ((j--) - i);
            else
                curr = height[i] * (j - i++);
            
            max = std::max(max, curr);
            
                
        }
        return max;
        
    }
};