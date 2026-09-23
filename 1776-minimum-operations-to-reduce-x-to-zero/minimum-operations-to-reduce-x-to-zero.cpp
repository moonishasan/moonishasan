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
        int subSum = 0;
        int left = 0;
        int maxlen = -1;
        for(int right = 0; right < nums.size(); right++){
            subSum += nums[right];
            while(subSum > target){
                subSum -= nums[left];
                left++;
            }
            if(subSum == target){
                int len = right - left + 1;
                maxlen = max(maxlen, len);
            }
        }
        return maxlen == -1 ? -1 : nums.size()-maxlen;
    }
};