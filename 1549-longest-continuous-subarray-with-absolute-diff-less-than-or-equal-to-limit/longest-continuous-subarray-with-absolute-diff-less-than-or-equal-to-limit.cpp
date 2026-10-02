
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // A multiset is similar to a set, but it allows duplicate elements and keeps elements sorted automatically.
        // This is useful because we need to find the minimum and maximum of our current window efficiently.
        
        multiset<int> st;

        int left = 0;
        int maxlen = 0;

        for(int right = 0; right < nums.size(); right++) {

            st.insert(nums[right]);

            while(*st.rbegin() - *st.begin() > limit) {

                st.erase(st.find(nums[left]));
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};