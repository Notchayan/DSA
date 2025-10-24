//https://leetcode.com/problems/longest-valid-parentheses/description/?envType=problem-list-v2&envId=dynamic-programming


class Solution {
    public:
        int longestValidParentheses(string s) {
            int n = s.size();
            int longest = 0;
            stack<int> st;
    
            for(int i = 0; i < n; i++){
                if(s[i]=='(') st.push(i);
                else {
                    if(!st.empty() && s[st.top()] == '(') {st.pop(); }
                    else st.push(i);
                }
            }
            if(st.empty()) longest = n;
            else{
                int r = n;
                int l = 0;
                while(!st.empty()){
                    l = st.top();st.pop();
                    longest = max(longest, r-l-1);
                    r = l;
                }
                longest = max(longest, r);
            }
            return longest;
        }
    };