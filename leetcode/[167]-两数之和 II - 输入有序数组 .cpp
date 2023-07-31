class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        int ret[2];
        while (l<r){
            if (numbers[l]+numbers[r]==target){
                ret[0]=l+1;
                ret[1]=r+1;
                break;
            } else if(numbers[l]+numbers[r]<target)
                l++;
            else
                r--;
        }
        return vector<int>(ret,ret+2);
    }
};