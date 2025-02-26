class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > dp[i - 1] + nums[i]){
                dp[i] = nums[i];
            }else{
                dp[i] = dp[i - 1] + nums[i];
            }

            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};