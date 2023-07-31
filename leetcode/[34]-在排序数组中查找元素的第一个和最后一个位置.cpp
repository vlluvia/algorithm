int findNums(vector<int> nums, int target){
    int left = 0, right = nums.size()-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid-1;
        else left = mid +1;
    }
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int id = findNums(nums, target);
    if(id == -1){
        res.push_back(-1);
        res.push_back(-1);
    }else{
        int left = id, right = id;
        while(left > 0){
            if(nums[left - 1] == target){
                left--;
            }else{
                break;
            }
        }
        while(right < nums.size()-1){
            if(nums[right + 1] == target){
                right++;
            }else{
                break;
            }
        }
        res.push_back(left);
        res.push_back(right);
    }
    return res;
}