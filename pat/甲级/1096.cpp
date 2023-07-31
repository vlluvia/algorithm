#include<bits/stdc++.h>
using namespace std;
int n;

vector<int> data,res;
int main(){
    scanf("%d", &n);
    int max=0;
    int sqr = sqrt(n);
    int i,j;
    for(i=2;i<=sqr;i++){
        if(n%i==0){
            data.push_back(i);
        }
    }

    for(i = 0;i<data.size();i++){
        int temp = data[i];
        int temp_max=0;
        int temp_n=n;
        vector<int> temp_res;
        for(j = i;j<data.size();j++){
            if(temp == data[j] && temp_n%temp == 0){
                temp_max++;
                temp_res.push_back(temp);
                temp_n/=temp;
                temp++;
            }else{
                break;
            }
        }
        if(temp_max > max){
            res = temp_res;
            max = temp_max;
        }
    }

    if(res.size()!=0){
        printf("%d\n",res.size());
        for(i=0;i<res.size();i++){
            printf("%d", res[i]);
            if(i!=res.size()-1)
                printf("*");
        }
    }else{
        printf("1\n");
        printf("%d",n);
    }
}
