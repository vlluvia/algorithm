int removeDuplicates(vector<int>& nums) {
    set<int> r(nums.begin(), nums.end());
    nums.assign(r.begin(), r.end());
    return r.size();
}