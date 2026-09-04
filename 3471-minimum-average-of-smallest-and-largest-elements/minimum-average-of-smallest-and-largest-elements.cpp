class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        vector<float> averages;
        sort(nums.begin(), nums.end());
        float mini = INT_MAX;
        for(int i = 0; i < n/2; i++){
            float val = (nums[i] + nums[n-i-1]) / 2.0;
            mini = min(mini, val);
        }
        return mini;
    }
};