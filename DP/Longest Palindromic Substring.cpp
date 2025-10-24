class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            if (n == 0) return "";
    
            vector<vector<int>> dp(n, vector<int>(n, 0));
            int maxlen = 1, start = 0;
    
            for (int i = 0; i < n; i++) {
                dp[i][i] = 1; 
            }
    
            for (int len = 2; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int j = i + len - 1;
                    if (s[i] == s[j]) {
                        if (len == 2 || dp[i + 1][j - 1]) {
                            dp[i][j] = 1;
                            if (len > maxlen) {
                                maxlen = len;
                                start = i;
                            }
                        }
                    }
                }
            }
    
            return s.substr(start, maxlen);
        }
    };
    