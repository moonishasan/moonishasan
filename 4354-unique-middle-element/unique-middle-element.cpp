class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int mid = n/2;
        for(int n : nums){
            freq[n]++;
        }
        if(freq[nums[mid]] == 1){
            return true;
        }
        return false;
    }
};