class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        int maxi_idx;
        int mini_idx;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                maxi_idx = i;
            }
            if(nums[i] == mini){
                mini_idx = i;
            }
        }
        // both deletions from front
        return min(min(max(mini_idx,maxi_idx) + 1, n - min(mini_idx, maxi_idx)), min(mini_idx, maxi_idx) + 1 + n - max(mini_idx, maxi_idx));
        // max(mini_idx,maxi_idx) + 1
        // // both deletions from back
        // n - min(mini_idx, maxi_idx) + 1
        // // one from back and one from front
        // min(mini_idx, maxi_idx) + 1 + n - max(mini_idx, maxi_idx) + 1;
        
    }
};