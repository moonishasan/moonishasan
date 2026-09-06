class Solution {
public:
    int countRotations(string s, int k) {
        string s2 = s;
        int count = 0;
        for(int rotation = 0; rotation < s.size(); rotation++){
            int score = 0;
            for(int i = 0; i < s2.size()-1; i++){
                if(s2[i] == s2[i+1]){
                    score++;
                }
            }
            if(score == k){
                count++;
            }
            char temp = s2[0];
            for(int i = 0; i < s2.size()-1; i++){
                s2[i] = s2[i+1];
            }
            s2[s2.size()-1] = temp;
        }
        return count;
    }
};