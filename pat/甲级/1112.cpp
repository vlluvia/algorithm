#include<bits/stdc++.h>
#include<string>

#define INF 1<<29

using namespace std;

int n;
string str, res;
map<char, int> temp;
bool a[127] = { false };
void pat1112() {
    cin >> n;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        temp[str[i]]++;
    }
    for (auto &item:temp) {
        if (item.second % n == 0) {
            bool flag = true;
            for (int i = 0; i < str.length();) {
                int num = 0;
                while (str[i] == item.first && i < str.size()) {
                    num++;
                    i++;
                }
                if (num != 0 && num % n != 0) {
                    a[item.first] = true;
                    break;
                } else {
                    i++;
                }
            }
        }else{
            a[item.first] = true;
        }
    }
    int i = 0;
    bool print[128] = { false };
    while(i<str.size())
    {
        if (!a[str[i]])//stucked
        {
            if (!print[str[i]])
            {
                cout << str[i];
                print[str[i]] = true;
            }
            str.replace(i, n - 1, "");
        }
        i++;
    }
    cout << endl << str;
}

int main() {
    pat1112();
    return 0;
}