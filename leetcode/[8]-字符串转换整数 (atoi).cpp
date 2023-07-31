int myAtoi(string str) {
    long long res = 0;
    bool flag = true, flag2 = true;
    for(int i=0; i < str.size() ; i++ ){

        if(str[i] >= '0' && str[i] <='9'){

            res += (str[i]-'0');
            res *= 10;
            if(flag2 && res/10 >= INT_MAX ){
                break;
            }else if(!flag2 && res / -10 <= INT_MIN ){
                break;
            }

            flag = false;
        }else if(str[i] == '-'){
            if(flag && str[i+1] >= '0' && str[i+1] <= '9'){
                flag2 = false;
            }else{
                break;
            }
        }else if(str[i] == '+'){
            if(flag && str[i+1] >= '0' && str[i+1] <= '9'){
                continue;
            }else{
                break;
            }
        }else{
            if(!flag){
                break;
            }else if(flag && str[i] !=' '){
                break;
            }
        }
    }
    if(!flag2)
        res *= -1;
    res /= 10;
    if(res >= INT_MAX){
        res = INT_MAX;
    }else if(res <= INT_MIN){
        res = INT_MIN;
    }
    return res;
}