class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int step = 0;
        int next_reach = nums[0];
        int reach = 0;
        for(int i=0;i < nums.size(); i++){
            next_reach = max(nums[i] + i, next_reach);
            if(next_reach >= nums.size() - 1) return step+1;
            if(i == reach){
                step++;
                reach = next_reach;
            }
        }
        return step;
    }
};