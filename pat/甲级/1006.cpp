#include<bits/stdc++.h>

using namespace std;

int n;
string unlock_man, lock_man;
char unlock_time[15], lock_time[15];

int compare(const char *time1, const char *time2) {
    int hour1, min1, sec1;
    int hour2, min2, sec2;
    sscanf(time1, "%d:%d:%d", &hour1, &min1, &sec1);
    sscanf(time2, "%d:%d:%d", &hour2, &min2, &sec2);
    int tm1, tm2;
    tm1 = hour1 * 3600 + min1 * 60 + sec1;
    tm2 = hour2 * 3600 + min2 * 60 + sec2;
    if (tm1 != tm2) return (tm1 > tm2) ? 1 : 0;
    return 2;
}

void pat1006() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cin >> unlock_man >> unlock_time >> lock_time;
            lock_man = unlock_man;
            continue;
        }

        char time1[15], time2[15];
        string man;
        cin >> man >> time1 >> time2;
        int r = compare(time1, unlock_time);
        if (r == 0) {
            unlock_man = man;
            strcpy(unlock_time, time1);
        }
        int r2 = compare(time2, lock_time);
        if (r2 == 1) {
            lock_man = man;
            strcpy(lock_time, time2);
        }
    }
    cout << unlock_man << " " << lock_man;
}


//int main() {
//    pat1006();
//    return 0;
//}