#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1092() {
    string a, b;
    cin >> a >> b;
    int temp[200];
    fill(temp, temp + 200, 0);
    for (int i = 0; i < a.size(); ++i) {
        temp[a[i]]++;
    }
    for (int i = 0; i < b.size(); ++i) {
        temp[b[i]]--;
    }
    int sum = 0;
    for (int i = 0; i < 200; ++i) {
        if (temp[i] < 0) {
            sum += abs(temp[i]);
        }
    }
    if (sum > 0) {
        printf("No %d", sum);
    } else {
        printf("Yes %d", a.size() - b.size());
    }
}

int main() {
    pat1092();
    return 0;
}