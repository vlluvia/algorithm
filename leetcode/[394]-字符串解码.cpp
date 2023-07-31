class Solution {
public:
    string decodeString(string s) {
        stack<char> c;
        stack<int> nums;
        int num = 0;
        string res="";
        int time = 0;
        for(int i=0;i<s.size(); i++){
            if(s[i] >= '0' && s[i] <='9'){
                if(time == 0){
                    time = s[i] -'0';
                }else{
                    time = time *10 + (s[i] -'0');
                }
            } else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                c.push(s[i]);
            }else if(s[i] == '[' ){
                c.push(s[i]);
                nums.push(time);
                time = 0;
            }else if(s[i] == ']'){
                int num = nums.top();
                nums.pop();
                string temp = "";
                while(c.top() != '['){
                    temp += c.top();
                    c.pop();
                }
                c.pop();
                for(int j = 0;j<num;j++){
                    for(int k = temp.size()-1;k>=0;k--)
                        c.push(temp[k]);
                }
            }
        }
        while(!c.empty() && c.top() != '['){
            res += c.top();
            c.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};