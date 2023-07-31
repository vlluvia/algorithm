#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

bool cmp(int i, int j) {
    return i > j;
}

bool cmp1(int i, int j) {
    return i < j;
}

void pat1037() {
    int nc, np;
    int ncdata[100050], npdata[100050];
    int res = 0;
    cin >> nc;
    for (int i = 0; i < nc; ++i) {
        cin >> ncdata[i];
    }
    cin >> np;
    for (int i = 0; i < np; ++i) {
        cin >> npdata[i];
    }
    sort(ncdata, ncdata + nc, cmp);
    sort(npdata, npdata + np, cmp);

    for (int i = 0; i < nc && i < np; ++i) {
        if (ncdata[i] < 0 || npdata[i] < 0) {
            break;
        }
        res += ncdata[i] * npdata[i];
    }

    sort(ncdata, ncdata + nc, cmp1);
    sort(npdata, npdata + np, cmp1);

    for (int i = 0; i < nc && i < np; ++i) {
        if (ncdata[i] > 0 || npdata[i] > 0) {
            break;
        }
        res += ncdata[i] * npdata[i];
    }

    cout << res << endl;
}


//int main() {
//    pat1037();
//    return 0;
//}