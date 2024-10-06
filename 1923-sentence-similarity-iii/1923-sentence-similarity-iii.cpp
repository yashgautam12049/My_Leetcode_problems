class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        //can be similar or not
        if(sentence1.size()<sentence2.size()){
            swap(sentence1,sentence2);
        }
        stringstream s1(sentence1);
        stringstream s2(sentence2);
        vector<string>mp1;
        vector<string>mp2;
        string word;
        while(s1>>word){
            mp1.push_back(word);
        }
        while(s2>>word){
            mp2.push_back(word);
        }
        
            //greater
            int l=0;
            int h=mp1.size()-1;
            //smaller
            int l1=0;
            int h1=mp2.size()-1;
                while(l1<mp2.size() && l<mp1.size() && mp1[l]==mp2[l1]){
                    l1++;
                    l++;
                }
                
                while(h1>=l1 && h>=0 && mp1[h]==mp2[h1]){
                    h1--;
                    h--;
                }

            
        return h1<l1;
    }
};