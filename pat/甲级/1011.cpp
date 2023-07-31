#include<bits/stdc++.h>

using namespace std;

void pat1011() {
    double sum = 1;
    int as[3];
    for (int i = 0; i < 3; ++i) {
        double s = -1;
        for (int j = 0; j < 3; ++j) {
            double l;
            cin >> l;
            if (l > s) {
                s = l;
                as[i] = j;
            }
        }
        sum *= s;
    }
    for (int a : as) {
        if (a == 0) {
            cout << "W"<<" ";
        } else if (a == 1) {
            cout << "T"<<" ";
        } else {
            cout << "L"<<" ";
        }
    }
    printf("%.2f",(sum*0.65-1)*2);

}


//int main() {
//    pat1011();
//    return 0;
//}