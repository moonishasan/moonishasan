class Solution {
public:
    int max_val(vector<int>& nums, int i){   // calculate max(nums[0...i])
        int maxi = INT_MIN;
        for(int j = 0; j <= i; j++){
            maxi = max(maxi, nums[j]);
        }
        return maxi;
    }
    int min_val(vector<int>& nums, int i){   // calculate min(nums[i...n-1])
        int mini = INT_MAX;
        for(int j = i; j < nums.size(); j++){
            mini = min(mini, nums[j]);
        }
        return mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            if(max_val(nums, i) - min_val(nums, i) <= k){
                return i;
            }
        }
        return -1;
    }
};