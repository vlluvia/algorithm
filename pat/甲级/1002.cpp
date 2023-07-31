#include<bits/stdc++.h>

#define INF 1<<30
using namespace std;

double data[1001] = {0};
int sum = 0;
int t, nk;
double ank;

void pat1002() {
    for (int i = 0; i < 2; ++i) {
        cin >> t;
        for (int j = 0; j < t; ++j) {
            cin >> nk >> ank;
            if(data[nk] == 0)
                sum++;
            data[nk] += ank;
            if(data[nk] == 0)
                sum--;
        }
    }
    printf("%d", sum);
    for (int j = 1000; j >= 0; --j) {
        if(data[j] != 0){
            printf(" %d %.1lf", j, data[j]);
        }
    }
}

int main() {
    pat1002();
    return 0;
}
