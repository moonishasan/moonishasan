class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        for(int ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                vowels.push_back(ch);
            }
        }
        int st = 0;
        int end = vowels.size()-1;
        while(st <= end){
            swap(vowels[st], vowels[end]);
            st++;
            end--;
        }
        int t = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i ]== 'e' || s[i] == 'i' || s[i] == 'o' || s[i] =='u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ){
                s[i] = vowels[t];
                t++;
            }
        }
        return s;
    }
};