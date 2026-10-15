class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> s;
            for(int j = i; j < n; j++){
                s.insert(nums[j]);
                int n = s.size() * s.size();
                ans += n;
            }
        }
        return ans;
    }
};