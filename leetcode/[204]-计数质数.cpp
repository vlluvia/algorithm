class Solution {
public:

    bool isPrime(int n){
        if(n <= 1) return false;
        int num = sqrt(n);
        for(int i=2; i<= num;i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int sum = 0;
        for(int i=2;i<n;i++){
            if(isPrime(i)){
                sum++;
            }
        }
        return sum;
    }
};