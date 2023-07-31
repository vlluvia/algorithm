#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1040() {
    string str;
    getline(cin, str);
    int max = 1;
    for (int i = 0; i < str.size(); ++i) {
        for (int j = str.size(); j > i; --j) {
            string temp = str.substr(i, j);
            if (temp.size() > max && temp[0] == temp[temp.size()-1]) {
                reverse(temp.begin(), temp.end());
                if (temp == str.substr(i, j)) {
                    max = temp.size();
                }
            }
        }
    }
    cout << max << endl;
}


//int main() {
//    pat1040();
//    return 0;
//}