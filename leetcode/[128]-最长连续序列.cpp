class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        sort(nums.begin(),nums.end());
        //删除重复元素
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int res=1,n=nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;++i){
            if(nums[i-1]+1==nums[i]){
                dp[i]=dp[i-1]+1;
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};