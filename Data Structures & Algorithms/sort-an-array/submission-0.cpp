class Solution {
public:
    void mergeSort(int start, int end, int mid, vector<int> &nums, vector<int> &ans){
        vector<int> nums1,nums2;
        for(int i=start;i<=mid;i++){
            nums1.push_back(nums[i]);
        }
        for(int j=mid+1;j<=end;j++){
            nums2.push_back(nums[j]);
        }
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        int k=start;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                ans[k++]=nums1[i++];
            }
            else{
                ans[k++]=nums2[j++];
            }
        }
        while(i<n){
            ans[k++]=nums1[i++];
        }
        while(j<m){
            ans[k++]=nums2[j++];
        }
        for(int p = start; p <= end; p++)
            nums[p] = ans[p];

    }
    void merge(vector<int>&nums,vector<int>&ans, int start,int end){
        if(start>=end){
            return;
        }
            int mid=start+(end-start)/2;
            merge(nums,ans,start,mid);
            merge(nums,ans,mid+1,end);
            mergeSort(start,end,mid,nums,ans);
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        merge(nums,ans,0,n-1);
        return nums;
    }
};