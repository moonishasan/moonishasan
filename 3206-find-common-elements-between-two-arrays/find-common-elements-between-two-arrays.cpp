class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int ans1 = 0;
        int ans2 = 0;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size(); i++){
           if(s2.find(nums1[i]) != s2.end()){
                ans1++;
           } 
        }  
        for(int i = 0; i < nums2.size(); i++){
            if(s1.find(nums2[i]) != s1.end()){
                ans2++;
            }
        }
        return {ans1, ans2};
    }
};