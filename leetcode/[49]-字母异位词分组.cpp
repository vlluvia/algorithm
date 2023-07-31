vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    map<string, vector<string>> r;
    for (int i = 0; i < strs.size(); ++i) {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        r[temp].push_back(strs[i]);
    }
    for(auto item: r){
        res.push_back(item.second);
    }
    return res;
}