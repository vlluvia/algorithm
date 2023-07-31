void dfs(const string &digits,decltype(digits.size()) index,string str,vector<string> &svec,const	map<char,string>& numstrMap){
    if(str.size()==digits.size()){svec.push_back(str);return;}
    string tempStr=numstrMap.at(digits.at(index));
    for (decltype(tempStr.size()) i = 0; i !=tempStr.size() ; ++i) {
        dfs(digits,index+1,str+tempStr.at(i),svec,numstrMap);
    }
}
vector<string> letterCombinations(string digits) {

    map<char, string> temp;
    temp['0'] = " ";
    temp['1'] = "!@#";
    temp['2'] = "abc";
    temp['3'] = "def";
    temp['4'] = "ghi";
    temp['5'] = "jkl";
    temp['6'] = "mno";
    temp['7'] = "pqrs";
    temp['8'] = "tuv";
    temp['9'] = "wxyz";
    vector<string> svec;
    if(digits != ""){
        dfs(digits,0,"",svec,temp);
    }
    return svec;
}