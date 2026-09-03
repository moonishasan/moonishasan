class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = INT_MAX;
        int count_odd = 0;
        for(int i = 0; i < nums1.size(); i++){
            mini = min(mini, nums1[i]);
            if(nums1[i] & 1){
                count_odd++;
            }
        }
        return mini&1 || count_odd == 0;
    }
};