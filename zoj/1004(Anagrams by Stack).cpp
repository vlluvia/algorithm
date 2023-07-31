#include <bits/stdc++.h>

using namespace std;

string a,b;
stack<char> s;
char t_action[100];
void dfs(int i, int o){
    if(i == a.size() && o == a.size()){
        for(int j = 0; j < a.size()*2; j++){
            printf("%c ", t_action[j]);
        }
        cout<<endl;
    }
    if(i < a.size()){
        s.push(a[i]);
        t_action[i+o] = 'i';
        dfs(i+1, o);
        s.pop();
    }
    if(!s.empty() && s.top() == b[o]){
        char t = s.top();
        s.pop();
        t_action[i+o] = 'o';
        dfs(i, o+1);
        s.push(t);
    }
}
bool isSame(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
int main() {
    while(cin>>a>>b){
        cout<<"["<<endl;
        if(isSame(a, b))
            dfs(0, 0);
        cout<<"]"<<endl;
    }
    return 0;
}