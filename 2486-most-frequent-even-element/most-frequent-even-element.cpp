class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }
        int maxi = 0;
        for(auto it : freq){
            if(it.first % 2 == 0){
                maxi = max(maxi, it.second);
            }
        }
        vector<int> ads;
        for(auto it : freq){
            if(it.second == maxi && it.first % 2 == 0){
                ads.push_back(it.first);
            }
        }
        if(ads.size() == 0){
            return -1;
        }
        sort(ads.begin(), ads.end());
        return ads[0];
        
    }
};