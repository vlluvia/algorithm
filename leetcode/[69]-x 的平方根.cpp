class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return 1;
        int left = 0, right = x;
        while(right - left > 1){
            int m = (right+left)/2;
            if(x/m<m)
                right = m;
            else
                left = m;
        }
        return left;
    }
};