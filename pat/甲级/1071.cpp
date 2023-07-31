#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

map<string, int> data;

void pat1071() {
    string str;
    getline(cin, str);

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    string temp = "";
    for (int i = 0; i < str.size(); ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
            temp += str[i];
        } else {
            if (!temp.empty()) {
                if (data.find(temp) != data.end()) {
                    data[temp]++;
                } else {
                    data[temp] = 1;
                }
                temp = "";
            }
        }
    }
    if(!temp.empty()){
        data[temp]++;
    }
    auto index = data.cbegin();
    for (auto it = data.cbegin(); it != data.cend(); it++) {
        if (it->second > index->second) {
            index = it;
        }
    }
    cout << index->first << " " << index->second << endl;
}


//int main() {
//    pat1071();
//    return 0;
//}