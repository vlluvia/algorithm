int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int mina = 10000;
    for(int i = 0; i< nums.size() - 2; i++){
        int left = i+1, right = nums.size() - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(abs(sum - target) < abs(mina - target)){
                mina = sum;
            }
            if(sum > target){
                right--;
            }else if(sum < target){
                left++;
            }else{
                return target;
            }
        }
    }

    return mina;
}