class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>alpha_store;
        for(auto it:word){
            alpha_store[it]++;
        }
        if(alpha_store.size()<=8){
            return word.size();
        }
        priority_queue<pair<int,char>>top_max;
        for(auto it:alpha_store){
            top_max.push({it.second,it.first});
        }
        int result=0;
        int wait=1;
        int mul=2;
        while(!top_max.empty()){
            int val=top_max.top().first;
            top_max.pop();
            if(wait>8){
                result+=(val*mul);
                if(wait%8==0) mul++;
            }
            else{
            result+=val;
            }
            wait++;
            //multiplication_factor
            //9-16 (2)
            //
        }
        return result;
    }
};