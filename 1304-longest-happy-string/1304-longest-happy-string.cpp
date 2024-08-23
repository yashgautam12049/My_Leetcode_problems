class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string result="";
        while(!pq.empty()){
            char max_occur_char=pq.top().second;
            int max_occur_count=pq.top().first;
            pq.pop();
            int len=result.size();
            if(len>=2 && result[len-1]==max_occur_char && result[len-2]==max_occur_char){
                if(pq.empty()) break;
                char max_occur_char2=pq.top().second;
                int max_occur_count2=pq.top().first;
                pq.pop();
                result+=max_occur_char2;
                max_occur_count2--;
                if(max_occur_count2>0){
                    pq.push({max_occur_count2,max_occur_char2});
                }
                pq.push({max_occur_count,max_occur_char});
            }
            else{
                result+=max_occur_char;
                max_occur_count--;
                if(max_occur_count>0){
                    pq.push({max_occur_count,max_occur_char});
                }
            }
        }
        return result;
    }
};