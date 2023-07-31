int maxArea(vector<int>& height) {
    int maxa = 0;
    for(int i=0;i < height.size(); i++){
        for(int j = i+1; j <height.size(); j++){
            int h = min(height[i], height[j]);
            if(maxa < h * (j-i)){
                maxa = h *(j-i);
            }
        }
    }
    return maxa;
}