class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res="";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i < a.size() || i < b.size(); i++){
            int a1 = 0, b1 = 0;
            if(i < a.size())
                a1 = a[i] - '0';
            if(i < b.size())
                b1 = b[i] -'0';
            int n = a1 + b1 + carry;
            res += to_string(n % 2);
            carry = n / 2;
        }
        if(carry){
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};