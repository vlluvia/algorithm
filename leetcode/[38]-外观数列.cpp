string countAndSay(int n) {
    string str = "1";
    for(int i=2;i <= n; i++){
        int sum = 1;
        char temp = str[0];
        string temp_str = "";
        for(int j = 1;j < str.size(); j++){
            if(str[j] != temp){
                temp_str += to_string(sum);
                temp_str += temp;
                sum = 1;
                temp = str[j];
            }else{
                sum++;
            }
        }
        if(sum != 0){
            temp_str += to_string(sum);
            temp_str += temp;
        }
        str = temp_str;
    }
    return str;
}