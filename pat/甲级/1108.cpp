#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num_size=0;
    double sum=0;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        bool flag = true;
        for(int j=0;j<str.size();j++){
            if(!(str[j] == '-' || (str[j]>='0' && str[j]<='9') || str[j]=='.')){
                flag = false;
                break ;
            }
        }
        if(flag){
            int dot = count(str.begin(),str.end(),'.');
            if(dot==1 || dot== 0){
                double num;
                stringstream ss;
                ss<<str;
                ss>>num;
                if(dot==1){
                    int p = str.find('.');
                    if(str.size()-p>3){
                        printf("ERROR: %s is not a legal number\n",str.c_str());
                        continue;
                    }
                }
                if(num>=-1000 && num<=1000){
                    sum+=num;
                    num_size++;
                }else{
                    printf("ERROR: %s is not a legal number\n",str.c_str());
                }

            }else{
                printf("ERROR: %s is not a legal number\n",str.c_str());
            }
        }else{
            printf("ERROR: %s is not a legal number\n",str.c_str());
        }
    }
    if(num_size>1){
        printf("The average of %d numbers is %.2lf\n",num_size, sum/num_size);
    }else if(num_size==0){
        printf("The average of 0 numbers is Undefined\n");
    }else{
        printf("The average of 1 number is %.2lf\n", sum/num_size);
    }
    return 0;
}