class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[10001];
        int n = nums.size();

        fill(dp, dp + n, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < n - 1; i++){
            int ableJump = nums[i];
            for(int j = 1; j <= ableJump; j++){
                if(i + j >= n) {
                    break;
                }

                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};