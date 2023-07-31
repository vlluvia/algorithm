#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;
.
int temp[505];

void pat1048() {
    memset(temp, 0, sizeof(temp));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        temp[l]++;
    }
    int a = 505;
    bool flag = false;
    for (int i = 1; i < 505; i++) {
        int remain = m - i;
        if (temp[i] && remain >= 0 && remain <= 500 && temp[remain]) {
            if (remain != i || (remain == i && temp[i] >= 2)) {
                flag = true;
                printf("%d %d\n", i, remain);
                break;
            }
        }
    }
    if (!flag)
        cout << "No Solution" << endl;
}


int main() {
    pat1048();
    return 0;
}