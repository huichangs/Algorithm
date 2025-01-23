class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int answer = INT_MIN;
        int sum = 0;

        for(int i : nums){
            sum += i;
        }

        for(int i = 0; i < nums.size(); i++){
            int specialSum = nums[i];
            int outlier = sum - (2 * specialSum);
            //cout << "specialSum " << specialSum << " outlier: " << outlier << endl;
            
            if(binary_search(nums.begin(), nums.begin() + i, outlier)){
                //cout << "findoutlier" << outlier << endl;
                answer = max(answer, outlier);
            }
            if(binary_search(nums.begin() + i + 1, nums.end(), outlier)){
                answer = max(answer, outlier);
            }
        }

        return answer;
    }
};