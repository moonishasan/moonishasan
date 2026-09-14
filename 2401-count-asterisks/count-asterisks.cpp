class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '|' && st.empty()){
                st.push('|');
            }
            else if(s[i] == '|' && !st.empty()){
                st.pop();
            }
            // if(st.top() == '|'){
            //     if(st.empty()){
            //         st.push('|');
            //     }
            //     else{
            //         st.pop();
            //     }
            // }
            if(st.empty()){
                if(s[i] == '*'){
                    count++;
                }
            }
        }
        return count;
    }
};