class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(), false);
        int maxa = 0;
        for(int i=0;i<candies.size();i++){
            if(candies[i] >= maxa){
                maxa = candies[i];
            }
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= maxa){
                res[i] = true;
            }
        }
        return res;
    }
};