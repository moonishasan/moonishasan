class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int start_hour = stoi(startTime.substr(0, 2));
        int start_min = stoi(startTime.substr(3, 5));
        int start_sec = stoi(startTime.substr(6));
        int end_hour = stoi(endTime.substr(0, 2));
        int end_min = stoi(endTime.substr(3, 5));
        int end_sec = stoi(endTime.substr(6));
        int hour_diff = (end_hour - start_hour) * 3600;
        int min_diff = (end_min - start_min) * 60;
        int sec_diff = end_sec - start_sec;
        int ans = hour_diff + min_diff + sec_diff;
        return ans;
    }
};