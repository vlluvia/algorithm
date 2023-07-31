class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == ""){
            return 0;
        }
        int maxa = 1;
        int temp[1000];
        for(int i = 0; i < s.size(); i++){
            fill(temp, temp+1000, 0);
            temp[s[i]] = 1;
            for(int j = i+1; j < s.size();j++){
                if(temp[s[j]]){
                    if(j - i > maxa){
                        maxa = j - i;
                    }
                    break;
                }else if(temp[s[j]] == 0 && j == s.size()-1){
                    if(j - i + 1 > maxa){
                        maxa = j - i + 1;
                        break;
                    }
                }
                temp[s[j]]++;
            }
        }
        return maxa;
    }
};