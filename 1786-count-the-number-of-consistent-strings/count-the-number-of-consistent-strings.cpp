class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        unordered_set<char> s(allowed.begin(), allowed.end());
        bool consistent = true;
        for(auto word : words){
            unordered_set<char> s2;
            for(char c : word){
                s2.insert(c);
            }
            for(char c : s2){
                if(s.find(c) == s.end()){
                    consistent = false;
                }
            }
            if(consistent){
                count++;
            }
            consistent = true;
        }
        return count;
    }
};