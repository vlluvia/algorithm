class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int maxa = 0, mina = prices[0];
        for(int i=0;i<prices.size();i++){
            maxa = max(maxa, prices[i] - mina);
            mina = min(mina, prices[i]);
        }
        return maxa;
    }
};