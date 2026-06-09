class MyHashMap {
public:
    vector<pair<int,int>> mp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int ind=-1;
        for(int i=0;i<mp.size();i++){
            if(mp[i].first==key){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            mp.push_back({key,value});
        }
        else{
            mp[ind].second=value;
        }
    }
    
    int get(int key) {
        for(int i=0;i<mp.size();i++){
            if(mp[i].first==key){
                return mp[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int ind=-1;
        for(int i=0;i<mp.size();i++){
            if(mp[i].first==key){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            return;
        }
        else{
            mp.erase(mp.begin()+ind);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */