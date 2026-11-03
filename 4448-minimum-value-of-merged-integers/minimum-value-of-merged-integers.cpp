class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        vector<int> merged;
        for(int i = 0; i < nums.size()-1; i+=2){
            string merg = to_string(nums[i]) + to_string(nums[i+1]);
            merged.push_back(stoi(merg));
        }      
        int ans = INT_MAX;
        for(int n : merged){
            ans = min(n, ans);
        }
        return ans;
    }
};