#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

int n, k;
int num_size = 0;

map<string, int> name2num;
map<int, string> num2name;
int data[2005][2005];
int person[2005];
int visit[2005];
map<string, int> res;

void dfs(int now, int &head, int &numMember, int &total) {
    numMember++;
    if (person[now] > person[head]) {
        head = now;
    }
    visit[now] = 1;
    for (int i = 0; i < num_size; ++i) {
        if (data[now][i] != 0) {
            total += data[now][i];
            data[now][i] = data[i][now] = 0;
            if (visit[i] == 0) {
                dfs(i, head, numMember, total);
            }
        }
    }
}

void pat1034() {
    memset(visit, 0, sizeof(visit));
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        string name1, name2;
        int t;
        cin >> name1 >> name2 >> t;
        int name1_num, name2_num;
        if (name2num.find(name1) != name2num.end()) {
            name1_num = name2num[name1];
        } else {
            name2num[name1] = num_size;
            num2name[num_size] = name1;
            name1_num = num_size;
            ++num_size;
        }

        if (name2num.find(name2) != name2num.end()) {
            name2_num = name2num[name2];
        } else {
            name2num[name2] = num_size;
            num2name[num_size] = name2;
            name2_num = num_size;
            ++num_size;
        }
        data[name1_num][name2_num] += t;
        data[name2_num][name1_num] += t;
        person[name1_num] += t;
        person[name2_num] += t;
    }
    for (int i = 0; i < num_size; ++i) {
        if (visit[i] == 0) {
            int head = i, numMember = 0, total = 0;
            dfs(i, head, numMember, total);
            if (total > k && numMember > 2) {
                res[num2name[head]] = numMember;
            }
        }
    }
    cout << res.size() << endl;
    map<string, int>::iterator it;
    for (it = res.begin(); it != res.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}


//int main() {
//    pat1034();
//    return 0;
//}