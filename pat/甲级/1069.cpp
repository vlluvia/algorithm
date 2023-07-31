#include<bits/stdc++.h>

#define INF 1<<29

void dfs(int number);

using namespace std;

void pat1069() {
    int number;
    cin >> number;
    dfs(number);
}

void dfs(int number) {
    int a[4] = {number % 10, number % 100 / 10, number % 1000 / 100, number / 1000};
    sort(a, a + 4);
    int min_number = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
    int max_number = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
    int res = max_number - min_number;
    switch (res){
        case 0:
        case 6174:
            printf("%04d - %04d = %04d\n",max_number,min_number,res);
            return;
        default:
            printf("%04d - %04d = %04d\n",max_number,min_number,res);
            dfs(res);
    }

}

//int main() {
//    pat1069();
//    return 0;
//}