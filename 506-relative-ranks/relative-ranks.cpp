class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        vector<int> temp = score;
        sort(temp.begin(), temp.end(), greater<int>());
        for(int i = 0; i < score.size(); i++){
            for(int j = 0; j < temp.size(); j++){
                if(score[i] == temp[j]){
                    if(j == 0){
                        ans[i] = "Gold Medal";
                    }
                    else if(j == 1){
                        ans[i] = "Silver Medal";
                    }
                    else if(j == 2){
                        ans[i] = "Bronze Medal";
                    }
                    else{
                        ans[i] = to_string(j+1);
                    }
                }
            }
        }
        return ans;
    }
};