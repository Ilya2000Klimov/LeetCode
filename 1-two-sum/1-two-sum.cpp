class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int>map; //Using unordered map
        for(int i=0;i<nums.size();i++)  //O(n)
        {
            int k=target-nums[i];   //k = the remainder of the number of target number - curent number => increase space complexity but reduses time complexity
            if(map.count(k)) //If you can find a non 0 number of needed numbers in the past numbers
            {
                return {map[k],i};  //Map[k], pulls  out the index of the right number
            }
            map[nums[i]]=i; //Puts the index of the current number into the number key of the map
        }
        return {-1,-1}; //if nothing is found, return {-1, -1}
    }
};
//vanessa is my girlfriend 
//she is so +cute+XXXDDDDDD
//HELL000 W000R1D
//COMPUTER READ THIS OUT LOUD NOW