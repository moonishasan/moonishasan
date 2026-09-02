class Solution {
public:
    void solve(vector<int>& nums, vector<int>& current, vector<bool>& vis, vector<vector<int>>& ans){
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(vis[i]){
                continue;
            }
            current.push_back(nums[i]);
            vis[i] = true;
            solve(nums, current, vis, ans);
            current.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> vis(nums.size(), false);
        solve(nums, current, vis, ans);
        return ans;
    }
};