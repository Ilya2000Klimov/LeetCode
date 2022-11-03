class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 1) return intervals;
        
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

/*class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 1) return intervals;
        
        vector <vector <int>> solutions;
        for (int i  = 0, j = 0; i < intervals.size(); i++)
        {
            solutions[j][0] = intervals[i][0];
            
            solutions[j][1] = intervals[i][1];
            
            for (int k = i + 1; k < intervals.size() && intervals[k][0] < solutions[j][1]; k++)
            {
                solutions[j][1] = max(intervals[k][1], solutions[j][1]);
            }
            
            j++;
        }
        
        return solutions;
    }
};*/