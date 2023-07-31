#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct student {
    char id[15];
    int score;
    int all_num;
    int classroom;
    int local_num;
};

student res[30050];

bool cmp(student s1, student s2) {

    if (s1.score != s2.score) return s1.score > s2.score;
    else return strcmp(s1.id, s2.id) < 0;
}

void getRank(int begin, int end,bool flag) {
    int l = 1;
    for (int k = begin; k <= end; ++k) {
        if (flag)
            res[k].local_num = l;
        else
            res[k].all_num = l;
        int l2 = 1;
        for (int j = k + 1; j <= end; ++j) {
            if (res[k].score == res[j].score) {
                if (flag)
                    res[j].local_num = l;
                else
                    res[j].all_num = l;
                ++k;++l2;
            } else {
                break;
            }
        }
        l += l2;
    }
}

void pat1025() {
    int n, index = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int classroom_size;
        cin >> classroom_size;
        for (int j = 1; j <= classroom_size; ++j) {
            char id[15];
            int score;
            cin >> id;
            cin >> score;
            student *s = new student;
            strcpy(s->id, id);
            s->score = score;
            s->classroom = i;
            res[index + j] = *s;
        }
        sort(res + index + 1, res + index + classroom_size + 1, cmp);
//        for (int y = index + 1; y <= index + classroom_size; ++y) {
//            cout <<"--> "<< res[y].id << " " << res[y].all_num << " " << res[y].classroom << " " << res[y].local_num << endl;
//        }
        getRank(index + 1, index + classroom_size,true);
//        for (int y = index + 1; y <= index + classroom_size; ++y) {
//            cout << res[y].id << " " << res[y].all_num << " " << res[y].classroom << " " << res[y].local_num << endl;
//        }
        index += classroom_size;
    }
    sort(res + 1, res + index + 1, cmp);
    getRank(1,index,false);
    cout << index << endl;
    for (int i = 1; i <= index; ++i) {
        cout << res[i].id << " " << res[i].all_num << " " << res[i].classroom << " " << res[i].local_num << endl;
    }
}

//int main() {
//    pat1025();
//    return 0;
//}