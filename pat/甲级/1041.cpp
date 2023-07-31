#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

int n;

void pat1041() {
    int c[100005];
    int data[100005];
    memset(c, 0, sizeof(c));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        c[num]++;
        data[i] = num;
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (c[data[i]] == 1) {
            cout << data[i] << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "None" << endl;
    }
}


//int main() {
//    pat1041();
//    return 0;
//}