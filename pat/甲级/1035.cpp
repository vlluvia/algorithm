#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct user {
    string name;
    string pass;
};

vector<user> users;

void pat1035() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name, pass;
        cin >> name >> pass;
        bool flag = false;
        for (int j = 0; j < pass.size(); ++j) {
            if (pass[j] == '1') {
                pass[j] = '@';
                flag = true;
            } else if (pass[j] == '0') {
                pass[j] = '%';
                flag = true;
            } else if (pass[j] == 'l') {
                pass[j] = 'L';
                flag = true;
            } else if (pass[j] == 'O') {
                pass[j] = 'o';
                flag = true;
            }
        }
        if (flag) {
            user u = {
                    name, pass
            };
            users.push_back(u);
        }
    }
    if (users.size() == 0) {
        if(n!=1) {
            printf("There are %d accounts and no account is modified", n);
        }else{
            printf("There is 1 account and no account is modified");
        }
    } else {
        cout << users.size() << endl;
        for (int i = 0; i < users.size(); ++i) {
            cout << users[i].name << " " << users[i].pass << endl;
        }
    }
}


//int main() {
//    pat1035();
//    return 0;
//}