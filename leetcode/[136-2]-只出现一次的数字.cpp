class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int item:nums){
            a = a ^ item;
        }
        return a;
    }
};