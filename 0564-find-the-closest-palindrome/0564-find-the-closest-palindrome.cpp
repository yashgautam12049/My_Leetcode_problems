class Solution {
public:
    long long func(long long firsthalf,bool check){
        long long resultnum=firsthalf;
        if(!check){
            firsthalf/=10;
        }
        while(firsthalf>0){

            resultnum=(resultnum*10)+(firsthalf%10);
            firsthalf/=10;
        }
        return resultnum;
    }
    string nearestPalindromic(string n) {
        int a = n.size();
        // even
       int mid=a/2;
       int first_half_len=(a%2==0)?mid:mid+1;
       long long firsthalf=stol(n.substr(0,first_half_len));
        vector<long long>possibility;
        long long orignal_num=stol(n);
        possibility.push_back(func(firsthalf,a%2==0));
        possibility.push_back(func(firsthalf+1,a%2==0));
        possibility.push_back(func(firsthalf-1,a%2==0));
        possibility.push_back((long)pow(10,a-1)-1);
        possibility.push_back((long)pow(10,a)+1);
        
        long long diff=INT_MAX;
        long long result=INT_MAX;
        for(auto it:possibility){
            if(it==orignal_num){
                continue;
            }
            if(abs(it-orignal_num)<diff){
                diff=abs(it-orignal_num);
                result=it;
            }
            else if(abs(it-orignal_num)==diff){
                result=min(result,it);
            }
        }
        return to_string(result);
    }
};