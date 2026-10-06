class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2){
            return -1;
        }
        // sort(nums.begin(), nums.end());
        // return nums[1];

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int n : nums){
            maxi = max(maxi, n);
            mini = min(mini, n);
        }
        for(int n : nums){
            if(n != mini && n != maxi){
                return n;
            }
        }
        return -1;
    }
};