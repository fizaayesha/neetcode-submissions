class MyHashSet {
public:
    vector<int> mp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        mp.push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)){
            return;
        }
        else{
            int ind=-1;
            for(int i=0;i<mp.size();i++){
                if(mp[i]==key){
                    ind=i;
                    break;
                }
            }
            mp.erase(mp.begin()+ind);
        }
    }
    
    bool contains(int key) {
        for(int i=0;i<mp.size();i++){
            if(mp[i]==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */