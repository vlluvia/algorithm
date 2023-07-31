#include<bits/stdc++.h>

#define INF 1<<29

using namespace std;

void pat1044() {

    int N,M,sum=0,maxSum=INT_MAX;
    scanf("%d%d",&N,&M);
    int A[N];
    vector<pair<int,int>>v;//存储加和最小且要大于M的一串数字的首尾位置
    for(int i=0;i<N;++i)
        scanf("%d",&A[i]);
    for(int i=0,j=0;i<N&&j<=N;)
        if(sum<M)
            sum+=A[j++];//sum<M，即令sum加上当前j指向的元素值，同时j向右移一个元素
        else{
            if(sum==M){//如果sum==M,表示当前这一串数字符合要求
                printf("%d-%d\n",i+1,j);//输出当前这一串数字的左界和右界
                maxSum=-1;//置maxSum为-1，表示已经找到了总和等于M的一组数字
            }
            else if(sum<maxSum){//如果sum>M&&sum<maxSum
                maxSum=sum;//更新maxSum
                v.clear();//清空vector
                v.push_back({i+1,j});//将当前这一串数字的首尾位置加入vector中
            }else if(sum==maxSum)//如果sum>M&&sum==maxSum
                v.push_back({i+1,j});//将当前这一串数字的首尾位置加入vector中
            sum-=A[i++];//sum-=A[i],i右移一个元素
        }
    if(maxSum!=-1)//maxSum不为-1，表示没有找到总和等于M的一组数字，输出vector中的数字
        for(int i=0;i<v.size();++i)
            printf("%d-%d\n",v[i].first,v[i].second);

}

int main() {
    pat1044();
    return 0;
}