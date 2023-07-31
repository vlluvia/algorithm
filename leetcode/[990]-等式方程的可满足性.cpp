class Solution {
public:
    int father[200];

    void initFather(){
        for(int i=0;i<200;i++){
            father[i] = i;
        }
    }
    int findFather(int a){
        while(a != father[a]){
            a = father[a];
        }
        return a;
    }

    void Union(int x, int y){
        int fx = findFather(x);
        int fy = findFather(y);
        if(fx != fy){
            father[fx] = fy;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        initFather();
        for(auto item:equations){
            if(item[1] == '='){
                int x = item[0] - 'a';
                int y = item[3] - 'a';
                Union(x , y);
            }
        }
        for(auto item:equations){
            if(item[1] == '!'){
                int x = item[0] - 'a';
                int y = item[3] - 'a';
                int fx = findFather(x);
                int fy = findFather(y);
                if(fx == fy) return false;
            }
        }
        return true;
    }
};