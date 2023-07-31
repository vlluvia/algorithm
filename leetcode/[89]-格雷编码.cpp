class Solution {
public:
    bool flag = false;
    vector<int> grayCode(int n) {
        vector<int> res;
        int size = pow(2, n);  // 格雷码总数
        for(int i=0; i!=size; ++i) res.push_back(i^(i>>1));  // i与i右移一位后的结果相异或
        return res;
    }

};