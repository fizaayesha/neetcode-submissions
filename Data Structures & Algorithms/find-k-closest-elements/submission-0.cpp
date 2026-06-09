class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n=arr.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({abs(arr[i]-x),arr[i]});// {2,8}{2,4}{1,5}
            if(pq.size()>k){
                cout<<pq.top().first<<" "<<pq.top().second<<endl;
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};