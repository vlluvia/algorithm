#include <bits/stdc++.h>

using namespace std;

void prefix_table(string pattern, int prefix[], int n) {
    prefix[1] = 0;
    int len = 0;
    int i = 1;
    while (i <= n) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i + 1] = len;
            i++;
        } else {
            if (len > 1) {
                len = prefix[len];
            } else {
                prefix[i + 1] = len;
                i++;
            }
        }
    }
}

int main() {
    string pattern = "ABABCABAA";
    string text    = "AIUJDGABABABCABAA";
    int prefix[10];
    int n = 9, i = 0, j = 0;
    prefix[0] = -1;

    prefix_table(pattern, prefix, n);

    while (i < text.size()) {
        if (j == n - 1 && text[i] == pattern[j]){
            printf("Found pattern at %d\n",i-j);
            j = prefix[j];
        }
        if(text[i] == pattern[j]){
            i++;j++;
        }else{
            j = prefix[j];
            if(j == -1){
                i++;j++;
            }
        }

    }
    return 0;
}