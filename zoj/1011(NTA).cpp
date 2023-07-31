#include<iostream>
#include<vector>
using namespace std;
const int mm=20;
class signal
{public:
    int lchild,rchild;
};
char tree[123456];
int n,m,k,h;
int tree_deep;
vector<signal>table[mm][mm];
void read_data()
{
    char ch;
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
        {
            table[i][j].clear();
            while(1)
            {
                signal ss;cin>>ss.lchild>>ss.rchild;
                table[i][j].push_back(ss);
                ch=cin.get();
                if(ch=='\n')break;
            }
        }
}
void read_tree()
{ char ch;
    tree_deep=0;///从0开始存
    for(int i=0;i<=h;i++)
        for(int j=0;j<(1<<i);j++)
        {
            cin>>ch;tree[tree_deep++]=ch;
        }
}
bool judge(int sig,int node)
{
    int sig1,sig2;
    if(tree[node]=='*'||node>=tree_deep)///若达到了叶子节点
    { ///判断信号合法
        if(sig<n-m)return false;
        else return true;
    }
    int k=tree[node]-'a';
    int left=node*2+1;///因为从0开始所有每次都得加1；
    int right=left+1;
    for(int i=0;i<table[sig][k].size();i++)
    {
        sig1=table[sig][k][i].lchild;
        sig2=table[sig][k][i].rchild;
        if(judge(sig1,left)&&judge(sig2,right))return true;
    }
    return false;
}
int main()
{ int cas=0;
    while(cin>>n>>m>>k)
    { if(n==0&&m==0&&k==0)break;
        read_data();
        if(cas&&n)
            cout<<"\n";
        cout<<"NTA"<<++cas<<":\n";
        while(cin>>h)
        {if(h==-1)break;
            read_tree();
            if(judge(0,0))cout<<"Valid\n";
            else cout<<"Invalid\n";
        }
    }
}
