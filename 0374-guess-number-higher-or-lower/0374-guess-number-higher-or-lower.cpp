/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n)
    {
        int low = 1;
        int high = n;
        int mid = 1;
        int store;
        
        while(low <= high)
        {
            mid = ((high - low) / 2) + low/*(((low + 1) / 2) + (high / 2))*/;
            store = guess(mid);
            if (store == 0)
                return mid;
            if (store < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return mid;
        
    }
};

// int binarySearch (vector<int> nums, int target)
//     {
//         int low = 0;
//         int high = nums.size()-1;
//         int mid;
//         //int res = -1;
//         while(low < high)
//         {
//             mid = ((low+high) / 2);
            
//             if (vector[mid] < target) low = mid;
//             else high = mid;
//         }
//         return res;
//     }