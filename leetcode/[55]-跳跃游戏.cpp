class Solution {
        public:
        bool canJump(vector<int>& nums) {
            bool flag = true;
            int next_max=nums[0];
            for(int i=0;i< nums.size();i++){
                if(i+nums[i] > next_max){
                    next_max = i+nums[i];
                }
                if(next_max == i){
                    break;
                }
            }
            return next_max >= nums.size()-1;
        }
};