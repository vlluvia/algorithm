class Solution {
public String reverseWords(String s) {
        String[] strs = s.split(" ");
        String res = "";
        for(int i=strs.length-1; i >= 0 ;i--){
            if(strs[i].equals("") || strs[i].equals(" ")) continue;
            if(i == strs.length-1)
                res += (strs[i]);
            else
                res += (" "+strs[i]);
        }
        return res;
    }
}