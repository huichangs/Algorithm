#include<math.h>
#include<iostream>
#include<algorithm>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer = 0;
        int answer_diff = 1000000000;

        sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++){
        //     cout << nums[i] << " ";
        // }

        for(int i = 0; i < nums.size() - 2; i++){
            int sum = 0;
            int part_target = -(nums[i] - target);
            int tmp_diff = 1000000000;

            int b = i + 1;
            int e = nums.size() - 1;

            while(b < e){
                int part_sum = nums[b] + nums[e];
                int part_diff = abs(part_sum - part_target);

                if(part_diff == 0){
                    sum = nums[i] + part_sum;
                    break;
                }
                if(part_diff < tmp_diff){
                    tmp_diff = part_diff;
                    sum = nums[i] + part_sum;
                }
                
                if(part_sum < part_target){
                    b++;
                }else{
                    e--;
                }
            }

            int diff = abs(sum - target);

            if(diff == 0){
                return target;
            }

            if(diff < answer_diff){
                answer = sum;
                answer_diff = diff;
            }
        }
        

        return answer;
    }
};