
class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int maxlen = 0;

        unordered_map<int, int> freq;

        for(int right = 0; right < n; right++) {

            int x = nums[right];
            bool valid = true;

            // Check whether adding x makes the window invalid
            for(auto [a, count] : freq) {

                // Case 1: a + x = existing element
                if(freq.count(a + x)) {
                    valid = false;
                    break;
                }

                // Case 2: a + b = x
                int b = x - a;

                if(freq.count(b)) {

                    // If a == b, need two distinct occurrences
                    if(a != b || count > 1) {
                        valid = false;
                        break;
                    }
                }
            }

            // Shrink window until it becomes valid
            while(!valid) {

                freq[nums[left]]--;

                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;

                // Recheck the new window
                valid = true;

                for(auto [a, count] : freq) {

                    if(freq.count(a + x)) {
                        valid = false;
                        break;
                    }

                    int b = x - a;

                    if(freq.count(b)) {
                        if(a != b || count > 1) {
                            valid = false;
                            break;
                        }
                    }
                }
            }

            // Add current element to the valid window
            freq[x]++;

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};