class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp="";
        dfs(0, 0, s, temp, res);
        return res;
    }

    void dfs(int num, int ind, string s, string temp, vector<string> &res){
        //cout<<"--> "<<temp<<" "<< num<<" "<<ind<<endl;
        if(temp.size() > s.size() + 3){
            return;
        }
        if(num == 4 ){
            if(temp.size() == s.size() + 3){
                res.push_back(temp);
            }
            return;
        }
        int t = 0;
        for(int j = 0; j < 3; j++){
            if(ind + j >= s.size()) return;
            t += (s[ind+j]-'0');
            if(t >= 0 && t<=255){
                // cout<<t<<endl;
                string tem = "";
                if(temp == "" || num == 4) tem += to_string(t);
                else tem = temp+"." + to_string(t);
                dfs(num+1, ind + j + 1, s, tem, res);
            }
            t *= 10;
        }
    }
};