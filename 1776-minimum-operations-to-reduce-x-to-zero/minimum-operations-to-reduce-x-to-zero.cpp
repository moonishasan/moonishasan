class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // find length of max subarray whose sum is sum(nums)-x
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        int target = sum - x;
        if(target < 0){
            return -1;
        }
        int left = 0;
        int sub_sum = 0;
        int maxLen = INT_MIN;
        for(int right = 0; right < nums.size(); right++){
            sub_sum += nums[right];
            while(sub_sum > target){
                sub_sum -= nums[left];
                left++;
            }
            if(sub_sum == target){
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen == INT_MIN ? -1 : nums.size()-maxLen;
    }
};