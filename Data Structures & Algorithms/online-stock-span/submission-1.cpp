class StockSpanner {
public:
    stack<int> st;
    vector<int> arr;
    vector<int> ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(i+1);
            }
            else{
                ans.push_back(i-st.top());
            }
            st.push(i);
        }
        return ans.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// 100 80 60 70