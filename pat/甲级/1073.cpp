#include<iostream>
#include<string.h>
using namespace std;

int main() {
    char str[10010];
    cin >> str;
    int len = strlen(str);
    if (str[0] == '-')
        printf("-");
    int postE = 0;
    while (str[postE] != 'E')
        postE++;
    int exp = 0;
    for (int i = postE + 2; i < len; i++)
        exp = exp * 10 + str[i] - '0';
    if (exp == 0){
        for (int i = 1; i < postE; i++)
            printf("%c", str[i]);
    }else{
        if (str[postE + 1] == '-'){
            printf("0.");
            for (int i = 1; i < exp; i++)
                printf("0");
            for (int i = 1; i < postE;i++)
                if (i != 2)
                    printf("%c", str[i]);
        }
        else{
            int temp = postE - 3;
            if (temp <= exp){
                for (int i = 1; i < postE; i++)
                    if (i != 2)
                        printf("%c", str[i]);
                for (int i = 0; i < exp - temp;i++)
                    printf("0");
            }
            else{
                for (int i = 1; i < postE; i++){
                    if (i != 2)
                        printf("%c", str[i]);
                    if (i - 2 == exp)
                        printf(".");
                }
            }
        }
    }
    return 0;
}