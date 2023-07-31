#include<bits/stdc++.h>
using namespace std;

struct node{
    string name;
    int height;
};
int n,k;
vector<node> data;

bool cmp(node a,node b){
    return a.height ==b.height? a.name<b.name: a.height>b.height;
}

int main(){

    cin>>n>>k;
    for(int i=0;i<n;i++){
        string name;
        int height;
        cin>> name>>height;
        data.push_back({name,height});
    }

    sort(data.begin(),data.end(),cmp);
    int row_size = n/k;
    int temp = 0;
    for(int i=0;i<k;i++){
        if(i==0){
            int row_all = row_size+n%k;
            if(row_all%2 == 1){
                for(int j=row_all-2;j>=temp;j-=2){
                    cout<<data[j].name<<" ";
                }
                for(int j=temp;j<row_all;j+=2){
                    cout<<data[j].name;
                    if(j+2<row_all){
                        cout<<" ";
                    }
                }
            }else{
                for(int j=row_all-1;j>=temp;j-=2){
                    cout<<data[j].name<<" ";
                }
                for(int j=temp;j<row_all;j+=2){
                    cout<<data[j].name;
                    if(j+2<row_all){
                        cout<<" ";
                    }
                }
            }
            temp+=(row_size+n%k);
        }else{
            int row_all = temp+row_size;
            if(row_size%2 == 1){
                for(int j=row_all-2;j>=temp;j-=2){
                    cout<<data[j].name<<" ";
                }
                for(int j=temp;j<row_all;j+=2){
                    cout<<data[j].name;
                    if(j+2<row_all){
                        cout<<" ";
                    }
                }
            }else{
                for(int j=row_all-1;j>=temp;j-=2){
                    cout<<data[j].name<<" ";
                }
                for(int j=temp;j<row_all;j+=2){
                    cout<<data[j].name;
                    if(j+2<row_all){
                        cout<<" ";
                    }
                }
            }
            temp+=row_size;
        }
        if(i!=k-1)
            cout<<endl;
    }

    return 0;
}