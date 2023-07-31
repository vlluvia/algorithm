class Solution {
public:
    static bool cmp(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
    string largestNumber(vector<Qint>& nums) {
        string res="";
        bool nonzero = false;
        sort(nums.begin(), nums.end(), cmp);
        for(auto s: nums){
            res+=to_string(s);
            if(s) nonzero = true;
        }
        return  nonzero ? res : "0";
    }
};