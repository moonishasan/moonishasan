class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& candidates, int target, vector<int>& current, int sum){
        // found valid combination
        if(sum == target){
            ans.push_back(current);
            return;
        }
        // invalid 
        if(i == candidates.size() || sum > target){
            return;
        }
        // take candidates[i]
        current.push_back(candidates[i]);
        solve(i, candidates, target, current, sum + candidates[i]);
        // skip candidates[i]
        current.pop_back();
        solve(i+1, candidates, target, current, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;

        solve(0, candidates, target, current, 0);

        return ans;
    }
};