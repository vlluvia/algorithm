#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,w[10010],dp[110],choice[10010][110],flag[10010];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    sort(w+1,w+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int v=m;v>=w[i];v--){
            if(dp[v]<=dp[v-w[i]]+w[i]){	//为了获得较小的结果序列，等于时也放
                dp[v]=dp[v-w[i]]+w[i];
                choice[i][v]=1;
            }else
                choice[i][v]=0;
        }
    }
    if(dp[m]!=m) printf("No Solution\n");
    else{
        int k=n,num=0,v=m;
        while(k){
            if(choice[k][v]==1){
                flag[k]=1;
                v-=w[k];
                num++;
            }else flag[k]=0;
            k--;
        }
        for(int i=n;i>0;i--){
            if(flag[i]){
                num--;
                printf(num?"%d ":"%d",w[i]);
            }
        }
        printf("\n");
    }
    return 0;
}