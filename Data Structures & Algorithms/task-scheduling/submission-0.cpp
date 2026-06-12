class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto i:tasks){
            mp[i]++;
        }
        priority_queue<int> pq; //count
        for(auto x:mp){
            pq.push(x.second);
        }
        int timer=0;
        while(!pq.empty()){
            vector<int> remain;
            int cycle=n+1;
            while(cycle && !pq.empty()){
                int task1=pq.top();
                pq.pop();
                if(task1>1){
                    remain.push_back(task1-1);
                }
                timer++;
                cycle--;
            }
            for(auto x:remain){
                pq.push(x);
            }
            if(pq.empty()){
                break;
            }
            timer+=cycle;
        }
        return timer;
    }
};
