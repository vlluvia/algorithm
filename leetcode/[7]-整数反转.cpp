class Solution {
public:
    int reverse(int x) {
        if(x == 0){
            return x;
        }else if(x == INT_MIN){
            return 0;
        }
        int t_x = abs(x);
        int flag = 0;
        long long res = 0;
        do{
            if(flag){
                res *=10;
                res += t_x%10;
            }else{
                if(t_x%10 != 0){
                    flag = 1;
                    res = t_x%10;
                }
            }
            t_x/=10;
        }while(t_x != 0);
        res = (x > 0)? res : -1 * res;
        if(res< INT_MAX && res >INT_MIN){
            return res;
        }else{
            return 0;
        }
    }
};