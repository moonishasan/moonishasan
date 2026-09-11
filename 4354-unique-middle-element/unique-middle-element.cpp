class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }
        if(freq[nums[nums.size()/2]] == 1){
            return true;
        }
        return false;
    }
};