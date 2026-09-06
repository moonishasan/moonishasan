class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_set<char> st(jewels.begin(), jewels.end());
        for(auto c : stones){
            if(st.find(c) != st.end()){
                count++;
            }
        }
        return count;
    }
};