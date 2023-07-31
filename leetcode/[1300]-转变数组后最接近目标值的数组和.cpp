class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int part = 0;
        int i;
        for (i = 0; i < arr.size(); ++ i) {
            int sum = part + arr[i] * (arr.size() - i);
            if (sum > target)
                break;
            part += arr[i];
        }
        if (i == arr.size())
            return arr.back();
        int remain = target - part;
        int l = remain / (arr.size() - i);
        int r = l + 1;
        if (remain - l * (arr.size() - i) <= r * (arr.size() - i) - remain)
            return l;
        else
            return r;
    }
};