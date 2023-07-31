class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        string str;
        for(int l=0;l < s.size();l++){
            for(int i = 0; i +l < s.size();i++){
                int j = i +l;
                if(l == 0){
                    dp[i][j] = 1;
                }else if(l == 1){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j] && l+1 > str.size()){
                    str = s.substr(i, l+1);
                }
            }
        }
        return str;
    }
};