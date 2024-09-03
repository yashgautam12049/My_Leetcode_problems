class Solution {
public:
    // int convert(char a){
    //     string s="";
    //     s+=a;
    //     return stoi(s);
    // }
    int getLucky(string s, int k) {
        string temp="";
        for(auto it:s){
            temp+=(to_string(it-'a'+1));
        }
        int result;
        while(k--){
            result=0;
            for(auto it:temp){
                result+=(it-'0');
            }
            temp=to_string(result);
        }
        return result;
    }
};