class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for(int i : nums){
            if(i > 0){
                s.insert(i);
            }
        }
        return s.size();
        // int ans = 0;
        // while(true){
        //     int mini = INT_MAX;
        //     for(int i : nums){
        //         if(i > 0){
        //             mini = min(mini, i);
        //         }
        //     }
        //     if(mini == INT_MAX){
        //         return ans;
        //     }
        //     for(int i = 0; i < nums.size(); i++){
        //         if(nums[i] > 0){
        //             nums[i] -= mini;
        //         }
        //     }
        //     ans++;
        // }
        // return ans;
    }
};