#include <bits/stdc++.h>

using namespace std;

int n, res = 0;
int data[5][5]={0};

int check(int x, int y){
    if(data[x][y] != 0){
        return 0;
    }
    bool flag = true;
    for(int i=0; i< n;i++){
        if(data[x][i] == 2){
            flag = false;
        }else if(data[x][i] == 1 && i < y){
            flag = true;
        }
    }
    if(!flag){
        return 0;
    }
    flag = true;
    for(int i=0; i < n;i++){
        if(data[i][y] == 2){
            flag = false;
        }else if(data[i][y] == 1 && i < x){
            flag = true;
        }
    }
    return flag;
}

void dfs(int x, int y,int temp_sum){
    if(check(x, y) == 0){
        return;
    }
    data[x][y] = 2;
    if(res < temp_sum){
        res = max(res, temp_sum);
    }
    for (int i = x; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(data[i][j] == 0){
                dfs(i, j, temp_sum+1);
            }
        }
    }
    data[x][y] = 0;
}
int main() {

    while(cin>>n && n != 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                if (c == 'X')
                    data[i][j] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (data[i][j] == 0) {
                    dfs(i, j, 1);
                }
            }
        }
        cout << res << endl;
        res = 0;
        fill(data[0], data[0]+5*5, 0);
    }
    return 0;
}