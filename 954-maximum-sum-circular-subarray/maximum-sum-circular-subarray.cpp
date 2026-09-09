class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot_sum = 0;
        for(int i : nums){
            tot_sum += i;
        }
        // calculate max contiguous subarray sum
        int ans1 = INT_MIN;
        int max_sum = 0;
        for(int i : nums){
            max_sum += i;
            ans1 = max(ans1, max_sum);
            if(max_sum < 0){
                max_sum = 0;
            }
        }
        // calculate min contiguous subarray sum
        int ans2 = INT_MAX;
        int min_sum = 0;
        for(int i : nums){
            min_sum += i;
            ans2 = min(ans2, min_sum);
            if(min_sum > 0){
                min_sum = 0;
            }
        }
        if(ans1 < 0){
            return ans1;
        }
        return max(ans1, tot_sum-ans2);
    }
};