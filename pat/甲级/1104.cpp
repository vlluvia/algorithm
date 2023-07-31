#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;
int n;
double sum = 0;

void pat1104() {
    cin >> n;
    double temp = 0;
    for (int i= 0; i < n; ++i) {
        cin >> temp;
        sum += temp*(n-i)*(i+1);
    }
    printf("%.2lf",sum);
}

int main() {
    pat1104();
    return 0;
}