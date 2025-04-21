class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int answer = INT_MAX;

        vector<int> minutes;

        for(int i = 0; i < timePoints.size(); i++){
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3));

            minutes.push_back(60 * h + m);
        }

        sort(minutes.begin(), minutes.end());

        for(int i = 0; i < minutes.size() - 1; i++){
            answer = min(minutes[i + 1] - minutes[i], answer);
        }

        answer = min(minutes[0] + 24 * 60 - minutes[minutes.size() - 1], answer);

        return answer;
    }
};