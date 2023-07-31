class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char,int> M1,M2;

        for(int i = 0; i < s.size();i++){
            M1[s[i]] = i;
            M2[t[i]] = i;
        }

        for(int i = 0; i < s.size();i++){
            if (M1[s[i]] != M2[t[i]]) return false;
        }

        return true;
    }
};