class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        unordered_set<float> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2; i++){
            float val = (nums[i] + nums[n-i-1]) / 2.0;
            s.insert(val);
        }
        return s.size();
    }
};