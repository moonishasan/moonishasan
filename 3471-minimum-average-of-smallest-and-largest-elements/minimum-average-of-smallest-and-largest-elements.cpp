class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        vector<float> averages;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2; i++){
            float val = ((float)nums[i] + nums[n-i-1]) / 2;
            averages.push_back(val);
        }
        float mini = INT_MAX;
        for(auto n : averages){
            mini = min(mini, n);
        }
        return mini;
    }
};