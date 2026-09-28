class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char> st;
        for(int i = 1; i < s.size(); i++){
            string ans = "";
            st.push('(');
            while(!st.empty()){
                if(s[i] == '('){
                    st.push('(');
                }
                else if(s[i] == ')'){
                    st.pop();
                }
                if(!st.empty()){
                    ans += s[i];
                }
                i++;   
            }
            res += ans;
        }
        return res;
    }
};