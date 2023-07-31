class Solution {
        public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> res;
            vector<int> pre(n, 1), end(n, 1);
            pre[0] = nums[0];
            end[n-1] = nums[n-1];
            for(int i = 1; i < n; i++){
                pre[i] = (nums[i] * pre[i - 1]);
            }
            for(int i = n-2; i >= 0 ;i--){
                end[i] = (nums[i] * end[i + 1]);
            }
            for(int i = 0;i < n;i++){
                if(i == 0)
                    res.push_back(end[i+1]);
                else if(i == n-1){
                    res.push_back(pre[i - 1]);
                }else{
                    res.push_back(pre[i-1] * end[i+1]);
                }
            }
            return res;
        }
};