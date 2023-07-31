#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;


void pat1084() {
    string origin_str, type_str,temp;
    cin >> origin_str >> type_str;
    transform(origin_str.begin(), origin_str.end(), origin_str.begin(), ::toupper);
    transform(type_str.begin(), type_str.end(), type_str.begin(), ::toupper);
    for (char i : origin_str) {
        bool flag = false;
        for (char j : type_str) {
            if (i == j) {
                flag = true;
                break;
            }
        }
        if(!flag&& temp.find(i) == -1){
            temp += i;
            cout<<i;
        }
    }
}


//int main() {
//    pat1084();
//    return 0;
//}