class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s =="") return 0;
        int sum = 0;
        int flag = true;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] !=' '){
                sum++;
            }else{
                if(sum!=0){
                    break;
                }
            }
        }
        return sum;
    }
};