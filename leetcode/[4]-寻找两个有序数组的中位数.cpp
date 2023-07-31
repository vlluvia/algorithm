class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int flag = (nums1.size() + nums2.size()) % 2;
        int mid = (nums1.size() + nums2.size()) / 2;
        mid = flag ? mid + 1 : mid;
        int ind = 0, i = 0, j = 0;
        int x, y;
        while(ind < mid){
            if(i < nums1.size() && j < nums2.size()){
                if(nums1[i] <= nums2[j]){
                    x = nums1[i++];
                }else{
                    x = nums2[j++];
                }
            }else{
                if( i < nums1.size() ){
                    x = nums1[i++];
                }else{
                    x = nums2[j++];
                }
            }

            ind++;
        }
        if(flag){
            return x / 1.0;
        }else{
            if(i < nums1.size() && j < nums2.size()){
                y = min(nums1[i], nums2[j]);
            }else{
                if( i < nums1.size() ){
                    y = nums1[i];
                }else{
                    y = nums2[j];
                }
            }
            return (x + y) / 2.0;
        }
    }
};