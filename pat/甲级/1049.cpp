#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1049() {
    int n;
    int sum;
    scanf("%d",&n);
    int now, left, right, a;
    a = 1;
    while(n/a){
        left = n / (a*10);
        right = n % a;
        now = n/a % 10;
        if(now == 0) sum += left * a;
        if(now == 1) sum += left * a + right + 1;
        if(now >= 2) sum += (left + 1) * a;
        a = a*10;
    }

    printf("%d",sum);
}

//int main() {
//    pat1049();
//    return 0;
//}