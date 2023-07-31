#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

const int inf = (1 << 31) - 1;
queue<int> q1;

void pat1029() {
    int n,m,t,t1,t2;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&t);
        q1.push(t);
    }
    q1.push(inf);
    scanf("%d",&m);
    int cnt=0,mid=(n+m-1)/2;
    for(int i=0;i<m;i++) {
        scanf("%d",&t);
        while(q1.front()<=t&&cnt<mid){
            cnt++;
            q1.pop();
        }
        if(cnt>=mid) break;			//注意这句不能放在最后，否则下例会输出12
        if(q1.front()>t&&cnt<mid)	//5 9 10 15 16 17
            cnt++;					//4 11 12 13 14
    }
    while(cnt<mid) {
        q1.pop();
        cnt++;
        t=inf;
    }
    printf("%d\n",min(q1.front(),t));

}


//int main() {
//    pat1029();
//    return 0;
//}