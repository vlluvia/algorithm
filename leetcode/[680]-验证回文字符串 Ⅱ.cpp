class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        int flag = dfs(i, j, s, 0);
        return flag;
    }
    bool dfs(int i, int j, string s, int time){
        if(time == 2){
            return false;
        }
        while(i <= j){
            if(s[i] == s[j]){
                i++; j--;
            }else{
                time++;
                return dfs(i+1, j, s, time) || dfs(i, j-1, s, time);
            }
        }
        return true;
    }
};