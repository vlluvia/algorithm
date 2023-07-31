class Solution {
public:
    string add(string num1, string num2){
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        for(int i=0, j=0;i<num1.size() || j < num2.size(); i++, j++){
            int n1=0, n2 = 0;
            if(i<num1.size()) n1 = num1[i] - '0';
            if(j<num2.size()) n2 = num2[j] - '0';
            int t = n1 + n2 + carry;
            res += to_string(t % 10);
            carry = t / 10;
        }
        if(carry != 0){
            res += to_string(carry % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        int idx = 1;
        string res= "0";
        if(num1 == "0" || num2 == "0"){
            return res;
        }
        for(int i=num2.size()-1;i >= 0;i--){
            int carry = 0;
            string temp_res;
            for(int j = 1;j < idx; j++){
                temp_res += '0';
            }
            for(int j = num1.size() -1; j >=0;j--){
                int n1 = num1[j] - '0';
                int n2 = num2[i] - '0';

                int t = n1 * n2 +carry;
                temp_res += to_string(t %10);
                carry = t /10;
            }
            if(carry) temp_res += to_string(carry);
            reverse(temp_res.begin(), temp_res.end());
            res = add(temp_res, res);
            idx++;
        }

        return res;
    }
};