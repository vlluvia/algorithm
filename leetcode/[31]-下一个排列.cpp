void reverse(vector<int> &nums, int begin, int end) {
    while (begin < end) {
        swap(nums[begin++], nums[end--]);
    }
}
void nextPermutation(vector<int> &nums) {
    for(int i = nums.size()-1; i >= 0; i--){
        if(i == 0){
            sort(nums.begin(), nums.end());
            break;
        }
        if(nums[i] > nums[i-1]){
            reverse(nums, i, nums.size()-1);
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] > nums[i - 1]) {
                    swap(nums[j], nums[i - 1]);
                    return;
                }
            }
        }
    }
}