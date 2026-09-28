class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        for(char c : s){
            if(c == '('){
                st.push('(');
                int len = st.size();
                ans = max(ans, len);
            }
            else if(c == ')'){
                st.pop();
            }
        }
        return ans;
    }
};