class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int maxV = 0;

        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]]++;
            maxV = max(maxV, nums[i]);
        }

        vector<int> dp(maxV + 1, 0);
        dp[1] = 1 * hashmap[1];

        for(int i = 2; i <= maxV; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + (i * hashmap[i]));
        }

        return dp[maxV];
    }
};