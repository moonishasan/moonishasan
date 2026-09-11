class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }
        int middle = nums[nums.size()/2];
        if(freq[middle] == 1){
            return true;
        }
        return false;
    }
};