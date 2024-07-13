class Solution {
public:
    int ans=0;
    void findba(string &s, int x, int y){
        int i=0;
        int j=0;
        int n=s.size();
        for(int j=0;j<n;j++){
            s[i]=s[j];
            i++;
            if(i>1 && s[i-2]=='b' && s[i-1]=='a'){
                        i=i-2;
                        ans+=y;
                }
        }

            //rest
            s.erase(s.begin()+i,s.end()); 
    }
    void findab(string &s, int x, int y){
        int i=0;
        int j=0;
        int n=s.size();
            for(int j=0;j<n;j++){
            s[i]=s[j];
            i++;
            if(i>1 && s[i-2]=='a' && s[i-1]=='b'){
                        i=i-2;
                        ans+=x;
                }
        }
            //rest
            s.erase(s.begin()+i,s.end());
    }
    
    int maximumGain(string s, int x, int y) {
        if(x>y){
            findab(s,x,y);
            findba(s,x,y);
        }
        else{
            findba(s,x,y);
            findab(s,x,y);
        }
        return ans;
    }
};