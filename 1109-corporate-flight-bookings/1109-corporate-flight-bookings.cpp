class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> prefDif(n+2, 0);
        vector<int> res(n, 0);
        
        for (int i = 0; i < bookings.size(); i++)
        {
            prefDif[bookings[i][0]-1] += bookings[i][2];
            prefDif[bookings[i][1]] -= bookings[i][2];
        }
        
        int sum = 0;
        
        for (int i = 0; i < res.size(); i++)
        {
            sum += prefDif[i];
            res[i] = sum;
        }
        
        
        
        return res;
    }
};