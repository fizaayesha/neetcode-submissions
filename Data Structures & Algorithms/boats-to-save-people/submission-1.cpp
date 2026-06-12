class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int start=0,end=n-1;
        int count=0;
        while(start<=end){
            if(start==end){
                count++;
                break;
            }
            if(people[end]+people[start]<=limit){
                start++;
                end--;
            }
            else{
                end--;
            }
            count++;
        }
        return count;
    }
};

//1 2 2 3 3