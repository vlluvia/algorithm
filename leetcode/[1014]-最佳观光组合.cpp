class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxa = 0, left=A[0];
        for(int i=1; i< A.size(); i++){
            maxa = max(maxa, A[i] - i + left);
            left = max(left, A[i] + i);
        }
        return maxa;
    }
};