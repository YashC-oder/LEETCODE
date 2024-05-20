class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int longest = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i); 
            } else {
                st.pop(); 

                if (st.empty()) {
                    st.push(i);
                } else {
                    longest = max(longest, i - st.top()); 
                }
            }
        }

        return longest;
    }
};