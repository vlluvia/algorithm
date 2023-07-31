vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    set<vector<int>> res;
    if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
    for (int k = 0; k < (int)nums.size() - 2; ++k) {
        for(int l = nums.size()-1;l >= 0; l--){
            if(k >= l)  break;
            int targ = target - nums[k]- nums[l], i = k + 1, j = l - 1;
            while (i < j) {
                if (nums[i] + nums[j] == targ) {
                    res.insert({nums[k], nums[i], nums[j], nums[l]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < targ) ++i;
                else --j;
            }
        }

    }
    return vector<vector<int>>(res.begin(), res.end());
}