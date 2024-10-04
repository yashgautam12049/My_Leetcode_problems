class Solution {
public:
    long long universal = 0;

    // Function to check if we can divide the players into pairs with sum 't'
    bool check(map<long long, long long> mp, long long t, vector<int>& skill) {
        for (int i = 0; i < skill.size(); i++) {
            if (t - skill[i] < 0) {
                return false;
            }
            if (mp[t - skill[i]] > 0) {
                mp[t - skill[i]]--;
            } else {
                return false;
            }
        }
        return true;
    }

    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        long long low = skill[0] * 2; // smallest possible sum (two smallest players)
        long long high = skill[n - 1] + skill[0]; // largest possible sum (largest + smallest)

        map<long long, long long> mp;
        map<long long, long long> mp1;
        for (long long i = 0; i < skill.size(); i++) {
            mp[skill[i]]++;
        }

        // Binary search for the correct 'universal' sum
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(mp, mid, skill)) {
                universal = mid; // if we find a valid sum, save it and try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1; // if not valid, increase the lower bound
            }
        }

        // If no valid sum found
        if (universal == 0) {
            return -1;
        }

        // Create the pairings and calculate the result
        for (long long i = 0; i < skill.size(); i++) {
            mp1[skill[i]] = (universal - skill[i]);
        }

        long long ans = 0;
        for (auto it : mp1) {
            ans += (it.first * it.second * mp[it.first]);
        }

        return ans / 2;
    }
};
