class Solution {
public:
set<vector<int>>st;
    void solve(int ind,vector<int>& candidates, int target,vector<int>&v){
        if(target==0){
            st.insert(v);
            return;
        }
        if(ind==candidates.size() || target<0){
            return;
        }
        //take
        // v.push_back(candidates[ind]);
        // solve(ind+1,candidates,target-candidates[ind],v);
        // v.pop_back();
        // solve(ind+1,candidates,target,v);
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            v.push_back(candidates[i]);
            solve(i + 1,candidates, target - candidates[i], v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>v;
        solve(0,candidates,target,v);
        for(auto it:st){
            result.push_back(it);
        }
        return result;
    }
};