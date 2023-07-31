class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto item:tokens){
            if(item == "/"){
                int x2 = s.top();
                s.pop();
                int x1 = s.top();
                s.pop();
                s.push(x1 / x2);
            }else if(item == "+"){
                int x2 = s.top();
                s.pop();
                int x1 = s.top();
                s.pop();
                s.push(x1 + x2);
            }else if(item == "-"){
                int x2 = s.top();
                s.pop();
                int x1 = s.top();
                s.pop();
                s.push(x1 - x2);
            }else if(item == "*"){
                int x2 = s.top();
                s.pop();
                int x1 = s.top();
                s.pop();
                s.push(x1 * x2);
            }else{
                int num = 0;
                int flag = 0;
                for(int i=0;i < item.size();i++){
                    if(item[i] == '-'){
                        flag = 1;
                        continue;
                    }
                    if(num ==0){
                        num = item[i] - '0';
                    }else{
                        num = num*10 + (item[i] - '0');
                    }
                }
                cout<<num<<endl;
                s.push(flag == 0? num : -1 *num);
            }
        }
        return s.top();
    }
};