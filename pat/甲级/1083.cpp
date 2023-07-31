#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct student {
    string name;
    string id;
    int grade;
};

int n, min_grade, max_grade;
vector<student> students;
vector<student> res;

bool cmp(student s1, student s2) {
    return s1.grade > s2.grade;
}

void pat1083() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        student s;
        cin >> s.name >> s.id >> s.grade;
        students.push_back(s);
    }

    cin >> min_grade >> max_grade;
    for (int i = 0; i < n; ++i) {
        if (students[i].grade >= min_grade && students[i].grade <= max_grade) {
            res.push_back(students[i]);
        }
    }

    if (res.size() == 0) {
        cout << "NONE" << endl;
    } else {
        sort(res.begin(), res.end(), cmp);
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i].name << " " << res[i].id << endl;
        }
    }

}


//int main() {
//    pat1083();
//    return 0;
//}