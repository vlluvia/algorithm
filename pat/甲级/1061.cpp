#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1061() {

    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    string DAY;
    int HH = 0, MM = 0;
    bool flag = false;
    for (int i = 0; i < str1.size() || i < str2.size(); ++i) {
        if (str1[i] == str2[i]) {
            if (!flag) {
                if (str1[i] >= 'A' && str1[i] <= 'G') {
                    int num = str1[i] - 'A' + 1;
                    if (num == 1) {
                        DAY = "MON";
                    } else if (num == 2) {
                        DAY = "TUE";
                    } else if (num == 3) {
                        DAY = "WED";
                    } else if (num == 4) {
                        DAY = "THU";
                    } else if (num == 5) {
                        DAY = "FRI";
                    } else if (num == 6) {
                        DAY = "SAT";
                    } else {
                        DAY = "SUN";
                    }
                    flag = true;
                }
            } else {
                if (str1[i] >= 'A' && str1[i] <= 'N') {
                    HH = str1[i] - 'A' + 10;
                    break;
                } else if (str1[i] >= '0' && str1[i] <= '9') {
                    HH = str1[i] - '0';
                    break;
                }

            }
        }
    }
    for (int i = 0; i < str3.size() || i < str4.size(); ++i) {
        if (str3[i] == str4[i]) {
            if ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')) {
                MM = i;
                break;
            }
        }
    }

    printf("%s %02d:%02d\n", DAY.c_str(), HH, MM);
}

//int main() {
//    pat1061();
//    return 0;
//}