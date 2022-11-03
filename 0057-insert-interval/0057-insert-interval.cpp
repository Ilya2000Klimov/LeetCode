class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector <vector <int>> solutions;
        int min = 0;
        int max = 0;
        for (int i  = 0; i < intervals.size(); i++)
        {
            min = intervals[i][0];
            
            max = intervals[i][1];
            
            for (int k = i + 1; k < intervals.size() && intervals[k][0] <= max; k++, i++)
            {
                max = std::max(intervals[k][1], max);
            }
            
            solutions.push_back({min, max});
        }
        
        return solutions;
    }
};