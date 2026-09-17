class Solution {
public:
    int getMini(vector<int>& nums){
        int mini = INT_MAX;
        for(int n : nums){
            mini = min(mini,n);
        }
        return mini;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> ans;
        for(int i = 0; i < k; i++){
            for(int i = 0; i < nums.size(); i++){
                int mini = getMini(nums);
                if(nums[i] == mini){
                    nums[i] = nums[i]*multiplier;
                    break;
                }
            }
            ans = nums;
        }
        return ans;

    }
};