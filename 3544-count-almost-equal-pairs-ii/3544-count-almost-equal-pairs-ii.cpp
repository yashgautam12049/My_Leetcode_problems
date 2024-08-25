class Solution {
public:
    string convert(int num, int max_digit) {
        string a = to_string(max_digit);
        string b = to_string(num);
        while (b.size() != a.size()) {
            b = '0' + b;
        }
        return b;
    }
    unordered_set<string> all_possibility(int num, int max_digit) {
        unordered_set<string> store_possibilty;
        string curr = convert(num, max_digit);
        int n = curr.size();
        store_possibilty.insert(curr);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // firs swap
                swap(curr[i], curr[j]);
                store_possibilty.insert(curr);
                for (int i_ = 0; i_ < n; i_++) {
                    for (int j_ = i_ + 1; j_ < n; j_++) {
                        // second swap
                        swap(curr[i_], curr[j_]);
                        store_possibilty.insert(curr);
                        swap(curr[j_], curr[i_]);
                        // if(curr[i_]!=curr[j_]){
                        // }
                    }
                }
                swap(curr[j], curr[i]);
            }
        }
        return store_possibilty;
    }
    int countPairs(vector<int>& nums) {
        int max_digit = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (auto it : all_possibility(nums[i], max_digit)) {
                if (mp.count(it)) {
                    result+=mp[it];
                }
            }
            mp[convert(nums[i], max_digit)]++;
        }
        return result;
    }
};