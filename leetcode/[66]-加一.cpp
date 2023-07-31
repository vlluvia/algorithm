class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size() - 1] += 1;
        vector<int> res;
        for(int i=digits.size()-1;i >= 0; i--){
            int n = digits[i] + carry;
            carry = n / 10;
            res.push_back( n%10 );
        }
        if(carry){
            res.push_back( carry );
        }
        reverse(res.begin(), res.end());
        return res;
    }
};