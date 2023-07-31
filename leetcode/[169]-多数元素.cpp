class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> data;
        for(int i =0;i<nums.size();i++){
            data[nums[i]]++;
            if(data[nums[i]] == nums.size()/2+1){
                return nums[i];
            }
        }
        return 0;
    }
};