class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            int score = 0;
            for(int j = i+1; j < n; j++){
                if((nums[i] % 2 == 0 && nums[j] % 2 != 0) || 
                (nums[i] % 2 != 0 && nums[j] % 2 == 0)){
                    score++;
                }
            }
            ans.push_back(score);
        }
        ans.push_back(0);
        return ans;
    }
};