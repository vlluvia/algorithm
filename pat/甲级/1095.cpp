#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

struct node {
    string id;
    int time;
    bool flag;
};

int n, k;
vector<node> data;

bool cmp1(node a, node b) {
    if (a.id != b.id) {
        return a.id < b.id;
    } else {
        return a.time < b.time;
    }
}

bool cmp2(node a, node b) {

    return a.time < b.time;

}

void pat1095() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string id, flag;
        int hour, minute, second;
        cin >> id;
        scanf("%d:%d:%d", &hour, &minute, &second);
        cin >> flag;
        int time = hour * 3600 + minute * 60 + second;
        bool f = flag == "in";
        node n = {
                id, time, f
        };
        data.push_back(n);
    }

    sort(data.begin(), data.end(), cmp1);
    vector<node> result;
    vector<string> m;
    map<string, int> res_max;
    int max_time = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (data[i].id == data[i + 1].id && data[i].flag == 1 && data[i + 1].flag == 0) {
            result.push_back(data[i]);
            result.push_back(data[i + 1]);
            res_max[data[i].id] += data[i + 1].time - data[i].time;
            max_time = max(res_max[data[i].id], max_time);
        }
    }
    sort(result.begin(), result.end(), cmp2);
    for (int i = 0; i < k; ++i) {
        int hour, minute, second;
        scanf("%d:%d:%d", &hour, &minute, &second);
        int time = hour * 3600 + minute * 60 + second;
        int sum = 0;
        int j=0;
        while (j<result.size() && result[j].time<=time){
            result[j].flag == 1?sum++:sum--;
            j++;
        }
        printf("%d\n", sum);
    }
    for (auto &it : res_max) {
        if (it.second == max_time)
            printf("%s ", it.first.c_str());
    }
    printf("%02d:%02d:%02d\n", max_time / 3600, max_time % 3600 / 60, max_time % 60);
}

int main() {
    pat1095();
    return 0;
}