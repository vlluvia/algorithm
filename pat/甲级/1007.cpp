#include<bits/stdc++.h>

using namespace std;

int n = 0;
int begin_num = 0, end_num = 0;
int sum = -1;
int seq[10005];

void pat1007() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    begin_num = end_num = 0;
    sum = seq[begin_num];
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = i; j < n; ++j) {
            s += seq[j];
            if (s > sum) {
                sum = s;
                begin_num = i;
                end_num = j;
            }
        }
    }
    if (sum < 0) {
        cout << 0 << " " << seq[0] << " " << seq[n - 1];
    } else {
        cout << sum << " " << seq[begin_num] << " " << seq[end_num];
    }
}


//int main() {
//    pat1007();
//    return 0;
//}