class Solution {
public:
    bool isPalindrome(string s) {
        string s_t, s2_t;
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
                s_t += s[i];
            }else if( s[i] >= 'A' && s[i] <= 'Z'){
                s_t +=(s[i] - 'A' + 'a');
            }
        }
        s2_t = s_t;
        reverse(s2_t.begin(), s2_t.end());

        cout<<s_t<<endl;
        cout<<s2_t<<endl;
        return s_t == s2_t;
    }
};