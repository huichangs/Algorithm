import java.util.*;

class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int result = 0;

        while(left < right){
            int CurAreaOfWater = (right - left) * Math.min(height[left], height[right]);
            result = Math.max(result, CurAreaOfWater);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return result;
    }
}