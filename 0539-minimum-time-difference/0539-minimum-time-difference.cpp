class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Sort the timePoints in increasing order
        sort(timePoints.begin(), timePoints.end());

        // Convert a time string to the number of minutes since 00:00
        auto toMinutes = [](const string& time) -> int {
            int hour = stoi(time.substr(0, 2)); // Extract hours
            int minute = stoi(time.substr(3, 2)); // Extract minutes
            return hour * 60 + minute;
        };

        // Initialize the minimum difference with the largest possible value
        int minDiff = 1440; // 24 hours * 60 minutes
        int n = timePoints.size();

        // Convert all time points to minutes since midnight
        vector<int> minutes;
        for (const auto& time : timePoints) {
            minutes.push_back(toMinutes(time));
        }

        // Compare adjacent time points (since array is sorted)
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        // Compare the last and the first time points across midnight
        minDiff = min(minDiff, 1440 - (minutes[n - 1] - minutes[0]));

        return minDiff;
    }
};