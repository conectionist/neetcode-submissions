class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pmap = 
        {
            {')','('},
            {']','['},
            {'}','{'}
        };

        auto validateParenthesis = [&st, &pmap](char ch)
        {
            return !st.empty() && st.top() == pmap[ch];
        };

        for(char ch : s)
        {
            switch(ch)
            {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                case ']':
                case '}':
                    if(!validateParenthesis(ch))
                        return false;
                    st.pop();
                default:
                    break;
            }
        }

        return st.empty();
    }
};
