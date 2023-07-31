class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> data;
        vector<int> num = nums;
        do{
            data.push_back(num);
            next_permutation(num.begin(), num.end());
        }while(num != nums);
        return data;
    }
};