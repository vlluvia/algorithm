#include <bits/stdc++.h>

using namespace std;

struct node{
    int up, right, bottom, left;
    int use;
}data[30];

bool flag = false;
int n;
int vis[5][5]={0};

void dfs(int ind){
    if(ind == n*n){
        flag = true;
        return;
    }
    int row = ind / n;
    int col = ind % n;
    for(int i = 0; i < n*n && !flag ;i++){
        if(data[i].use == 1){
            continue;
        }
        if(row > 0 && data[i].up != data[vis[row-1][col]].bottom)
            continue;
        if(col > 0 && data[i].left != data[vis[row][col-1]].right)
            continue;
        vis[row][col] = i;
        data[i].use = 1;
        dfs(ind+1);
        data[i].use = 0;
    }
}

int main() {
    int in = 1;
    while(scanf("%d",&n) && n) {
        flag = false;
        fill(vis[0], vis[0]+5*5, 0);
        for (int i = 0; i < n * n ; i++) {
            scanf("%d %d %d %d",&data[i].up,&data[i].right,&data[i].bottom,&data[i].left);
            data[i].use = 0;
        }
        dfs(0);

        if(in!=1)
            printf("\n");
        if (flag)
            printf("Game %d: Possible\n", in);
        else
            printf("Game %d: Impossible\n", in);
        in++;

    }
    return 0;
}