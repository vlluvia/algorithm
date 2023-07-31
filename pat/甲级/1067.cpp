#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1067() {
    int n, temp[100005];
    int res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        temp[num] = i;
    }
    int begin = 1;
    while (true) {
        if (temp[0] == 0) {
            bool flag = false;
            for (int i = begin; i < n; ++i) {
                if (temp[i] != i) {
                    swap(temp[0], temp[i]);
                    res++;
                    flag = true;
                    begin = i;
                    break;
                }
            }
            if (!flag)
                break;
        } else {
            swap(temp[temp[0]], temp[0]);
            res++;
        }
    }
    cout << res << endl;
}


//int main() {
//    pat1067();
//    return 0;
//}