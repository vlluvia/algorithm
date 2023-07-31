#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct man {
    string name;
    int age;
    int worth;
};

vector<man> data;
int n, k;

bool cmp(man m1, man m2) {
    if (m1.worth == m2.worth) {
        if (m1.age == m2.age) {
            return m1.name < m2.name;
        } else {
            return m1.age < m2.age;
        }
    } else {
        return m1.worth > m2.worth;
    }
}

void pat1055() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string name;
        int age, worth;
        cin >> name >> age >> worth;
        man m = {
                name, age, worth
        };
        data.push_back(m);
    }
    sort(data.begin(), data.end(), cmp);

    for (int j = 1; j <= k; ++j) {
        int m, amin, amax;
        bool flag = false;
        int index = 0;
        cin >> m >> amin >> amax;
        printf("Case #%d:\n", j);
        for (int i = 0; i < data.size(); ++i) {
            if (data[i].age >= amin && data[i].age <= amax) {
                printf("%s %d %d\n", data[i].name.c_str(), data[i].age, data[i].worth);
                flag = true;
                index++;
                if (index == m) {
                    break;
                }
            }
        }

        if (!flag) {
            cout << "None" << endl;
        }
    }

}

//int main() {
//    pat1055();
//    return 0;
//}