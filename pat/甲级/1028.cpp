#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct student {
    int id;
    string name;
    int grade;
};

int n, c;
vector<student> students;

bool cmp1(student s1, student s2) {
    return s1.id < s2.id;
}

bool cmp2(student s1, student s2) {
    if (s1.name.compare(s2.name) == 0) {
        return s1.id < s2.id;
    }
    return s1.name.compare(s2.name) < 0;
}

bool cmp3(student s1, student s2) {
    if (s1.grade == s2.grade) {
        return s1.id < s2.id;
    }
    return s1.grade < s2.grade;
}

void pat1028() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        int id, grade;
        string name;
        cin >> id >> name >> grade;
        student s = {
                id, name, grade
        };
        students.push_back(s);
    }

    switch (c) {
        case 1: {
            sort(students.begin(), students.end(), cmp1);
            break;
        }
        case 2: {
            sort(students.begin(), students.end(), cmp2);
            break;
        }
        case 3: {
            sort(students.begin(), students.end(), cmp3);
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%06d %s %d\n", students[i].id, students[i].name.c_str(), students[i].grade);
    }
}


//int main() {
//    pat1028();
//    return 0;
//}