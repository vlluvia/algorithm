class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> data;
        if(s.size() < 10) return {};
        for(int i=0; i < s.size()-10 + 1; i++){
            string temp = s.substr(i, 10);
            data[temp]++;
        }
        vector<string> res;
        for(auto item: data){
            if(item.second >= 2){
                res.push_back(item.first);
            }
        }
        return res;
    }
};