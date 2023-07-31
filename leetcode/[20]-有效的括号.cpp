bool isValid(string s) {
    stack<char> temp;
    for(int i =0; i < s.size();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            temp.push(s[i]);
        }else if(s[i] == ')'){
            if(temp.size() == 0) return false;
            if(temp.top() == '('){
                temp.pop();
            }else{
                return false;
            }
        }else if(s[i] == '}'){
            if(temp.size() == 0) return false;
            if(temp.top() == '{'){
                temp.pop();
            }else{
                return false;
            }
        }else{
            if(temp.size() == 0) return false;
            if(temp.top() == '['){
                temp.pop();
            }else{
                return false;
            }
        }
    }
    if(temp.size()!=0)
        return false;
    else
        return true;
}