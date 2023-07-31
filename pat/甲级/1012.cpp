#include<bits/stdc++.h>

using namespace std;

int all_student, check_student;
double data[2005][5];
int check_data[2005];
int check_result[2005][2];

void pat1012() {
    cin >> all_student >> check_student;
    for (int i = 0; i < all_student; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> data[i][j];
        }
        data[i][4] = (data[i][1] + data[i][2] + data[i][3]) / 3.0;
    }
    for (int k = 0; k < check_student; ++k) {
        cin >> check_data[k];
    }

    for (int i = 0; i < check_student; ++i) {
        for (int j = 0; j < all_student; ++j) {
            if (check_data[i] == data[j][0]) {
                int c_rank = 1, m_rank = 1, e_rank = 1, a_rank = 1;
                for (int k = 0; k < all_student; ++k) {
                    if (data[k][1] > data[j][1]) {
                        c_rank++;
                    }
                    if (data[k][2 ] > data[j][2]) {
                        m_rank++;
                    }
                    if (data[k][3] > data[j][3]) {
                        e_rank++;
                    }
                    if (data[k][4] > data[j][4]) {
                        a_rank++;
                    }
                }
                int max = 100000;
                if (a_rank < max) {
                    check_result[i][0] = a_rank;
                    check_result[i][1] = 4;
                    max = a_rank;
                }
                if (c_rank < max) {
                    check_result[i][0] = c_rank;
                    check_result[i][1] = 1;
                    max = c_rank;
                }
                if (m_rank < max) {
                    check_result[i][0] = m_rank;
                    check_result[i][1] = 2;
                    max = m_rank;
                }
                if (e_rank < max) {
                    check_result[i][0] = e_rank;
                    check_result[i][1] = 3;
                    max = e_rank;
                }
                break;
            }
            check_result[i][0] = -1;
            check_result[i][1] = -1;
        }
    }
    for (int l = 0; l < check_student; ++l) {
        if (check_result[l][0] == -1) {
            cout << "N/A" << endl;
        } else {
            cout << check_result[l][0] << " ";
            if (check_result[l][1] == 1) {
                cout << "C" << endl;
            } else if (check_result[l][1] == 2) {
                cout << "M" << endl;
            } else if (check_result[l][1] == 3) {
                cout << "E" << endl;
            } else {
                cout << "A" << endl;
            }

        }
    }
}


//int main() {
//    pat1012();
//    return 0;
//}