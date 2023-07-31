#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct book {
    int id;
    string title;
    string author;
    string keywords;
    string publisher;
    int year;
};

vector<book> books;
int n;

bool cmp(book book1, book book2) {
    return book1.id < book2.id;
}

void pat1022() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id, year;
        string title, author, keywords, publisher;
        cin >> id;
        getchar();
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        cin >> year;
        book b = {
                id, title, author, keywords, publisher, year
        };
        books.push_back(b);
    }
    sort(books.begin(), books.end(), cmp);
    int m;
    cin >> m;
    getchar();
    for (int i = 0; i < m; ++i) {
        int pre_num = 0;
        string q;
        getline(cin, q);
        int a = q.find(": ");
        string pre = q.substr(0, a);
        stringstream ss;
        ss << pre;
        ss >> pre_num;
        string pos = q.substr(a + 2, q.size() - 1);
        cout << q << endl;
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            switch (pre_num) {
                case 1: {
                    if (books[j].title == pos) {
                        printf("%07d\n", books[j].id);
                        flag = true;
                    }
                    break;
                }
                case 2: {
                    if (books[j].author == pos) {
                        printf("%07d\n", books[j].id);
                        flag = true;
                    }

                    break;
                }
                case 3: {
                    int t = books[j].keywords.find(pos);
                    if (t != -1) {
                        printf("%07d\n", books[j].id);
                        flag = true;
                    }
                    break;
                }
                case 4: {
                    if (books[j].publisher == pos) {
                        printf("%07d\n", books[j].id);
                        flag = true;
                    }
                    break;
                }
                case 5: {
                    stringstream ss2;
                    int y;
                    ss2 << pos;
                    ss2 >> y;
                    if (books[j].year == y) {
                        printf("%07d\n", books[j].id);
                        flag = true;
                    }
                    break;
                }
                default:
                    break;
            }
        }

        if (!flag) {
            cout << "Not Found" << endl;
        }
    }
}


//int main() {
//    pat1022();
//    return 0;
//}