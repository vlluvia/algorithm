class Solution {
public:
    bool isHappy(int n) {
        int last = n;
        int count = 0;
        while(n != 1  && count < 500){
            last = n;
            int sum = 0;
            while(n){
                int num = (n % 10) * (n % 10);
                n /= 10;
                sum += num;
            }
            if(sum != 1 && last == sum ) return false;
            n = sum;
            count++;
        }
        return n == 1;
    }
};