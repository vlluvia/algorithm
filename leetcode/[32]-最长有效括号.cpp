int longestValidParentheses(string s) {
    if(s == "") return 0;
    int size = s.size(), dp[size] = {0}, maxLength = 0;
    for (int i = 1; i < size; i++) {
        if (s[i] == ')') {
            int p = i - dp[i - 1] - 1;
            if (p >= 0 && s[p] == '(') {
                dp[i] += (dp[i - 1] + 2);
                if (p > 1) {
                    dp[i] += dp[p - 1];
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
    }
    return maxLength;
}