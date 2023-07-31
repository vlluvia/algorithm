class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        for(int i = 1; i <= numRows; i++){
            int t = 0;
            if(numRows!=1)
                t = i == numRows? 2 * numRows - 2*1 :2 * numRows - 2*i;
            else
                t = 1;
            int ind = i-1;
            int temp = 0;
            while(ind < s.size()){
                res += s[ind];
                if(i == 1 || i == numRows)
                    ind += t;
                else{
                    if(temp % 2 == 0){
                        ind += t;
                    }else{
                        ind += (2*i-2);
                    }
                    temp++;
                }
            }
        }
        return res;
    }
};