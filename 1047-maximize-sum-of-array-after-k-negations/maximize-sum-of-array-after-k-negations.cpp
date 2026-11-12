class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        while(k != 0){
            int mini = INT_MAX;
            for(int i = 0; i < n; i++){
                mini = min(mini, nums[i]);
            }
            for(int i = 0; i < n; i++){
                if(nums[i] == mini){
                    nums[i] = (-1) * nums[i];
                    break;
                }
            }
            k--;
        }
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        return sum;
    }
};