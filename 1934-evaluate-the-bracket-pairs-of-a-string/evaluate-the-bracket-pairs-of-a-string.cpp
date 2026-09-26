class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(int i = 0; i < knowledge.size(); i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '('){
                ans += s[i];
            }
            else{
                string curr = "";
                i++;
                while(s[i] != ')'){
                    curr += s[i];
                    i++;
                }
                if(mpp.find(curr) != mpp.end()){
                    ans += mpp[curr];
                }
                else{
                    ans += '?';
                }
            }
        }
        return ans;
    }
};