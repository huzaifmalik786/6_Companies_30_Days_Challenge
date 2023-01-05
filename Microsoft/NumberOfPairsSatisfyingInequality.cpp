//link to solution: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/submissions/872128112/


class Solution {
public:
    long long int count;

    void checkcount(vector<int>& nums, int start, int mid, int end, int d){
        int l=start, r= mid+1;
        while(l<=mid && r<=end){
            if(nums[l]<= nums[r]+d){
                l++;
                count+= end-r+1;
            }
            else{
                r++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end+1);
        return;
    }

    void mergesort(vector<int>& nums, int start, int end, int d){
        if(start==end){
            return;
        }
        int mid= (start+end)/2;
        mergesort(nums, start, mid, d);
        mergesort(nums, mid+1, end, d);
        checkcount(nums, start, mid, end, d);
        return;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        count= 0;
        int n= nums1.size();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]= nums1[i]-nums2[i];
        }
        mergesort(v,0,n-1,diff);
        return count;
    }
};
