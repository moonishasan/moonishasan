class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        unordered_set<int> frnds(friends.begin(), friends.end());
        for(int i = 0; i < order.size(); i++){
            if(frnds.count(order[i])){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};