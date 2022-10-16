class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int center = binarySearch(nums, target);
        
        if(center == -1) return {-1, -1};
        
        int low = center;
        int high = center;
        
        while (low >= 0 && nums[low] == target) low--;
        
        while (high < nums.size() && nums[high] == target) high++;
        
        return {++low, --high};
    }
    
    int binarySearch (vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        //int res = -1;
        while(low <= high)
        {
             mid = ((high - low) / 2) + low; //mid = ((low+high) / 2);
                 
            if (nums[mid] == target) return mid;
            
            if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

// int guessNumber(int n)
//     {
//         int low = 1;
//         int high = n;
//         int mid = 1;
//         int store;
        
//         while(low <= high)
//         {
//             mid = ((high - low) / 2) + low/*(((low + 1) / 2) + (high / 2))*/;
//             store = guess(mid);
//             if (store == 0)
//                 return mid;
//             if (store < 0)
//                 high = mid - 1;
//             else
//                 low = mid + 1;
//         }
//         return mid;
        
//     }