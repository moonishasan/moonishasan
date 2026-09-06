class Solution {
public:
    int countRotations(string s, int k) {
        int count = 0;
        for(int rotation = 0; rotation < s.size(); rotation++){
            int score = 0;
            for(int i = 0; i < s.size()-1; i++){
                if(s[i] == s[i+1]){
                    score++;
                }
            }
            if(score == k){
                count++;
            }
            char temp = s[0];
            for(int i = 0; i < s.size()-1; i++){
                s[i] = s[i+1];
            }
            s[s.size()-1] = temp;
        }
        return count;
    }
};