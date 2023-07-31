class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;
        int b = -1,e = -1;
        int x = newInterval[0], y = newInterval[1];
        int flag = 1;
        for(int i = 0;i < intervals.size(); i++){
            if(intervals[i][0] <= x && y <= intervals[i][1]){
                res.push_back(intervals[i]);
                b = i;
                e = i+1;
                break;
            }else if(intervals[i][0] >= x && y >= intervals[i][1]){
                flag = 1;
                continue;
            }else if(intervals[i][0] <= y && y <= intervals[i][1]){
                if(b != -1){
                    res.push_back({intervals[b][0], intervals[i][1]});
                }else{
                    res.push_back({x, intervals[i][1]});
                }
                e = i+1;
                break;
            }else if(y < intervals[i][0]){
                if(b != -1){
                    res.push_back({intervals[b][0], y});
                }else{
                    res.push_back({x, y});
                }
                e = i;
                break;
            }else if(intervals[i][0] <= x && x <= intervals[i][1]){
                b = i;
            }else{
                res.push_back(intervals[i]);
            }
        }
        if(e != -1)
            for(int i = e;i < intervals.size(); i++){
                res.push_back(intervals[i]);
            }
        if(b != -1 && e == -1){
            res.push_back({intervals[b][0], y});
        }
        else if(b == -1 && e == -1){
            res.push_back(newInterval);
        }
        return res;
    }
};