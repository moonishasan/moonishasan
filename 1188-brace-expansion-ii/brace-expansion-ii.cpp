class Solution {
public:

    // Concatenate every string from A with every string from B
    set<string> combine(set<string>& A, set<string>& B) {

        set<string> result;

        for(string a : A) {
            for(string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }


    set<string> solve(string& s, int& i) {

        // Stores the complete result of this expression
        set<string> result;

        // Current part that we are building
        set<string> curr;

        // Empty string initially
        curr.insert("");

        while(i < s.size() && s[i] != '}') {

            // --------------------------------
            // CASE 1: comma
            // --------------------------------
            if(s[i] == ',') {

                // Comma means OR / UNION
                // Add current expression to result
                result.insert(curr.begin(), curr.end());

                curr.clear();
                curr.insert("");

                i++;
            }

            // --------------------------------
            // CASE 2: opening brace
            // --------------------------------
            else if(s[i] == '{') {

                i++; // skip '{'

                // Solve everything inside {}
                set<string> inside = solve(s, i);

                // Concatenate current expression
                // with everything inside braces
                curr = combine(curr, inside);

                i++; // skip '}'
            }

            // --------------------------------
            // CASE 3: normal character
            // --------------------------------
            else {

                string ch(1, s[i]);

                set<string> single;
                single.insert(ch);

                // Concatenate current expression
                // with this character
                curr = combine(curr, single);

                i++;
            }
        }

        // Add the final part
        result.insert(curr.begin(), curr.end());

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        // set is already sorted
        return vector<string>(ans.begin(), ans.end());
    }
};