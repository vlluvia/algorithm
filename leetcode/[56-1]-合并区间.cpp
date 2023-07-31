class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<bool> vis(intervals.size(), 0);
        sort(intervals.begin(), intervals.end());
        for(int i=0;i< intervals.size();i++){
            if(vis[i]) continue;
            vis[i] = 1;
            int x = intervals[i][0], y = intervals[i][1];
            for(int j=i+1; j < intervals.size(); j++){
                if(intervals[j][0] <= x && y <= intervals[j][1]){
                    x = intervals[j][0];
                    y = intervals[j][1];
                    vis[j] = 1;
                }else if(intervals[j][0] >= x && y >= intervals[j][1]){
                    vis[j] = 1;
                }else if(intervals[j][0] <= y && y <= intervals[j][1]){
                    y = intervals[j][1];
                    vis[j] = 1;
                }else if(intervals[j][0] <= x && x <= intervals[j][1]){
                    x = intervals[j][0];
                    vis[j] = 1;
                }
            }
            res.push_back({x,y});
        }

        return res;
    }
};