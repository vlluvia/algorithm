#include<bits/stdc++.h>

#define INF 1<<29
using namespace std;

struct cu {
    int index;  //  用户的序号
    int remain_time;    //剩余时间，刚开始是该用户需要处理业务的时间
};
int n, m, k, q;
string res[1005];   //结果
int times[1005];
int queries[1005];

map<int, vector<cu>> mp;
void pat1014() {
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; ++i) {
        cin >> times[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> queries[i];
    }
    int init_capacity = 0;
    int t = 1;  //填满mp时的位置，之后往mp放入用户只要+1
    if (n * m > k) {
        init_capacity = k / n + 1;
    } else {
        init_capacity = m;
    }
    //初始化mp队列将mp填满（n * m < k），或则填满k各用户（n * m > k）
    for (int i = 1; i <= init_capacity; ++i) {
        if (n * m > k && i == init_capacity) {
            for (int j = 1; j <= k % n; ++j) {
                cu c = {
                        t, times[t]
                };
                mp[j].push_back(c);
                ++t;
            }
        } else {
            for (int j = 1; j <= n; ++j) {
                cu c = {
                        t, times[t]
                };
                mp[j].push_back(c);
                ++t;
            }
        }
    }
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << mp[i][j].index << " ";
//        }
//        cout << endl;
//    }
    bool f = true;  //mp 是否全为空
    int hour = 8, minute = 0;
    while (f) {
        //获取mp中所有窗口第一个用户（0）中那个需要花费时间最少的用户
        int min = 10000;
        int min_index = 0;
        for (int i = 1; i <= n; ++i) {
            if (mp[i].size() != 0) {
                if (mp[i][0].remain_time < min) {
                    min = mp[i][0].remain_time;
                    min_index = i;
                }
            }
        }
        //换算时间，并格式化输入到res对应的序号中
        minute += min;
        if (minute / 60 > 0) {
            hour += (minute / 60);
            minute = minute % 60;
        }
        char s[6];
        sprintf(s, "%02d:%02d", hour, minute);
        res[mp[min_index][0].index] = s;
//        cout << "min_index:" << min_index << endl;
//        cout << "index:" << mp[min_index][0].index << endl;
//        cout << "hour:" << hour << ",minute:" << minute << endl;
        //将mp中所有窗口第一个用户中所需时间减掉那个最少花费的用户的办理时间
        for (int i = 0; i <= n; ++i) {
            if (mp[i].size() != 0) {
                mp[i][0].remain_time -= min;
            }
        }
        // 当这个队列的第一个结束时间已经超过17:00，则清空该队列
        if (hour * 60 + minute >= 17 * 60) {
//             cout << "----------------min_index:" << min_index << endl;
            mp[min_index].clear();
        }else{
            mp[min_index].erase(mp[min_index].begin());
        }
        //如果黄线以外还有用户等待，就放到该队列里，同时如果第一个结束时间已经超过17:00，就不放入
        if (t <= k && n * m < k && hour * 60 + minute < 17 * 60) {
            cu c = {
                    t, times[t]
            };
            mp[min_index].push_back(c);
            t++;
        }
        //判断mp所有队列是否为空，为空就说明每个队列最后一个用户处理完了跳出循环
        int sumt = 0;
        for (int i = 1; i <= n; ++i) {
            if(mp[i].empty()){
                sumt++;
            }
        }
        f = sumt != n;
    }

    for (int l = 1; l <= q; ++l) {
        if (res[queries[l]]!="") {
            cout << res[queries[l]] << endl;
        }else{
            cout << "Sorry" << endl;
        }
    }
}


//int main() {
//    pat1014();
//    return 0;
//}