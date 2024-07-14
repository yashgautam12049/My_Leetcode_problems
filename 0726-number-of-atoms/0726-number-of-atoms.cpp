class Solution {
public:
    string countOfAtoms(string formula) {
        // normal scenario
        int n = formula.size();
        string temp = "";
        string digit="";
        stack<map<string,int>>st;
        st.push(map<string,int>());
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                map<string,int>temp=st.top();
                st.pop();
                i++;
                string mult;
                while(i<n && formula[i] >= 48 && formula[i] <= 57){
                    mult+=formula[i];
                    i++;
                }
                int num=mult.empty()?1:stoi(mult);
                for(auto it:temp){
                    string a=it.first;
                    int b=it.second;
                    b*=num;
                    temp[a]=b;
                }
                for(auto it:temp){
                    string a=it.first;
                    int b=it.second;
                    st.top()[a]+=b;
                }
            }
            else if ((formula[i] >= 65 && formula[i] <= 90)) {
                temp+=formula[i];
                i++;
                while (i<n && formula[i] >= 97 && formula[i] <= 122) {
                    temp+=formula[i];
                    i++;
                }
                // st.push(formula[i]);
                // string 
                while (i<n && formula[i] >= 48 && formula[i] <= 57) {
                    digit += formula[i];
                    // mp[temp] = digit;
                    i++;
                }
                int c=digit.empty()?1: stoi(digit);
                st.top()[temp]+=c;
                // st.push()
                digit = ""; // empty digit
                temp = "";
            }
        }
        map<string,int>ans(begin(st.top()),end(st.top()));
        string answer="";
        for(auto it:ans){
            string ele=it.first;
            answer+=ele;
            int count=it.second;
            if(count>1){
                string ab=to_string(count);
                answer+=ab;
            }
        }
        return answer;





    }
};