class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long answer = 0;
        int n = points.size();
        int m = points[0].size();

        vector<long long> dp(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[j] = points[i][j] + dp[j];
            }

            for(int j = 1; j < m; j++){
                dp[j] = max(dp[j], dp[j - 1] - 1);
            }

            for(int j = m - 2; j >= 0; j--){
                dp[j] = max(dp[j], dp[j + 1] - 1);
            }

        }

        for(int i = 0; i < m; i++){
            answer = max(answer, dp[i]);
        }


        return answer;
        
    }
};