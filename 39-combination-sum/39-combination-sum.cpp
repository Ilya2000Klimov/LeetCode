class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i, vector<int> &cur, vector<int> &candidates, int target) {
        if(target == 0) {
            // We have a solution
            ans.push_back(cur);
            return;
        }
        
        if(target < 0) {
            // We overshot
            return;
        }
        
        if(i >= candidates.size()) {
            return;
        }
        
        solve(i+1, cur, candidates, target);
        
        cur.push_back(candidates.at(i));
        solve(i, cur, candidates, target-candidates.at(i));
        if(!cur.empty()) {
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur(0, 1);
        solve(0, cur, candidates, target);
        return ans;
    }
};