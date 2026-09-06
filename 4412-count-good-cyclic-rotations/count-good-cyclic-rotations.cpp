class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        long long total = 0;
        for(int n : nums){
            total += n;
        }
        long long first = 0;
        int half = n/2;
        for(int i = 0; i < half; i++){
            first += nums[i];
        }
        int count = 0;
        for(int rotation = 0; rotation < nums.size(); rotation++){  
            if(first > total - first){
                count++;
            }
            int outgoing = nums[rotation];
            int incoming = nums[(rotation+half)%n];
            first = first - outgoing + incoming;
        }
        return count;
    }
};