class Solution {
    bool monotoneIncreasing(vector<int>& nums){
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }
    bool monotoneDecreasing(vector<int>& nums){
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                return false;
            }
        }
        return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2){
            return true;
        }
        if(monotoneDecreasing(nums) || monotoneIncreasing(nums)){
            return true;
        }
        return false;
    }
};