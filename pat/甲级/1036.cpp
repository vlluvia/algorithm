#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;


void pat1036() {
    string boy, girl, boy_id, girl_id;
    int boy_grade = 150, girl_grade = -1;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string name, gender, id;
        int grade;
        cin >> name >> gender >> id >> grade;
        if (gender == "M") {
            if (grade < boy_grade) {
                boy = name;
                boy_id = id;
                boy_grade = grade;
            }
        } else {
            if (grade > girl_grade) {
                girl = name;
                girl_id = id;
                girl_grade = grade;
            }
        }
    }
    if (girl_grade == -1) {
        cout << "Absent" << endl;
    } else {
        cout << girl << " " << girl_id << endl;
    }
    if (boy_grade == 150) {
        cout << "Absent" << endl;
    } else {
        cout << boy << " " << boy_id << endl;
    }


    if (boy_grade != 150 && girl_grade != -1) {
        cout << girl_grade - boy_grade << endl;
    } else {
        cout << "NA" << endl;
    }
}


//int main() {
//    pat1036();
//    return 0;
//}