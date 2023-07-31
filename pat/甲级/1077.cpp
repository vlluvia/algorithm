#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char str[110][300];
    int min = 300;
    cin.get();
    for (int i = 0; i < n; i++){
        cin.getline(str[i], 300);
        int len = strlen(str[i]);
        if (len<min)
            min = len;
        reverse(str[i], str[i] + len);
    }
    for (int i = 0; i < min; i++)
        for (int j = 1; j < n; j++)
            if (str[0][i] != str[j][i]){
                if (i == 0)
                    printf("nai");
                else
                    for (int z = i - 1; z >= 0; z--){
                        if (z == 0 && str[0][0] == ' ')
                            break;
                        printf("%c", str[0][z]);
                    }
                return 0;
            }
    printf("%s", str[0]);
    return 0;
}