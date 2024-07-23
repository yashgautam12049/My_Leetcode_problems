class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> st(deadends.begin(), deadends.end());
        if(st.find("0000") != st.end()) return -1;
        queue<string> q;
        q.push("0000");
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string a = q.front();
                q.pop();
                if (a == target) {
                    return level;
                }
                for (int i = 0; i < 4; i++) {
                    char ch = a[i];
                    char inc = (ch == '9') ? '0' : ch + 1;
                    char dec = (ch == '0') ? '9' : ch - 1;
                    a[i] = inc;
                    if (st.find(a) == st.end()) {
                        st.insert(a);
                        q.push(a);
                    }
                    a[i] = dec;
                    if (st.find(a) == st.end()) {
                        st.insert(a);
                        q.push(a);
                    }
                    a[i] = ch;
                }
            }
            level++;
        }
        return -1;
    }
};