string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0){
        return "";
    }
    int ind = 0;
    string res = "";
    while(true){
        bool flag = false;
        char temp;
        for(int i=0;i < strs.size(); i++){
            if(strs[i].size() <= ind){
                flag = true;
                break;
            }
            if( i == 0 ){
                temp = strs[i][ind];
            }else{
                if(strs[i][ind] != temp){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            break;
        ind++;
        res += temp;
    }
    return res;
}