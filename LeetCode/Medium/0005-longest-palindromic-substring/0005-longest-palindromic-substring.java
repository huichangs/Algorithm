class Solution {
    public String longestPalindrome(String s) {
        String answer = s.substring(0, 1);

        for(int i = 0; i < s.length() - 1; i++){
            String center = isPalindrome(s, i, i);
            String side = isPalindrome(s, i, i + 1);

            if(center.length() > answer.length()) answer = center;
            if(side.length() > answer.length()) answer = side;
        }

        return answer;
    }

    String isPalindrome(String s, int left, int right){
        while(left >= 0 && right < s.length() && (s.charAt(left) == s.charAt(right))){
            left--;
            right++;
        }

        return s.substring(left + 1, right);
    }
}