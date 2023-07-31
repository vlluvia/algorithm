#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1058() {
    int g1, g2, s1, s2, k1, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    int g3 = g1 + g2;
    int s3 = s1 + s2;
    int k3 = k1 + k2;
    int carry = 0;
    if (k3 / 29 > 0) {
        carry = k3 / 29;
        k3 = k3 % 29;
    }
    s3+= carry;
    if (s3 / 17 > 0) {
        carry = s3 / 17;
        s3 %=  17;
    } else{
        carry = 0;
    }
    g3 += carry;
    printf("%d.%d.%d", g3, s3, k3);
}

//int main() {
//    pat1058();
//    return 0;
//}