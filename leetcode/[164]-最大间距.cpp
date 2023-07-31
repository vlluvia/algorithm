class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int maxa = 0;
        for(int i=0; i< nums.size()-1; i++){
            maxa = max(maxa, nums[i+1] - nums[i]);
        }
        return maxa;
    }
};