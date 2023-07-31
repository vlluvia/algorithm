class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        string result="";
        if(len==0)
            return result;
        int maxLen=0;
        int start=0;
        int end=0;
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int j=0;j<len;j++){
            for(int i=0;i<j;i++){
                if(s[i]==s[j]&&(j-i<=2||dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};