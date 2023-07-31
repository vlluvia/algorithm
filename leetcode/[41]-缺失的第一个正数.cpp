class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int idx=1;
        for(int i=0; i < nums.size(); i++){
            int mina = nums[i], minid = i;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] < mina){
                    mina = nums[j];
                    minid = j;
                }
            }
            int temp = nums[minid];
            nums[minid] = nums[i];
            nums[i] = temp;

            if( mina > 0) {
                if(i != 0 && nums[i] == nums[i-1]) continue;
                if(idx != mina)
                    return idx;
                idx++;
            }
        }
        return idx;
    }
};