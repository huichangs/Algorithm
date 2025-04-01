class Solution {
public:
    string longestPalindrome(string s) {
        string answer;
        int longestSize = 0;

        for(int i = 0 ; i < s.size(); i++){
            int left = i;
            int right = i;

            while(left >= 0 && right < s.size() && (s[left] == s[right])){
                left--;
                right++;
            }

            if(longestSize < right - left + 1){
                answer = s.substr(left + 1, right - left - 1);
                longestSize = right - left + 1;
            }

            left = i;
            right = i + 1;

            while(left >= 0 && right < s.size() && (s[left] == s[right])){
                left--;
                right++;
            }
            
            if(longestSize < right - left + 1){
                answer = s.substr(left + 1, right - left - 1);
                longestSize = right - left + 1;
            }
        }

        return answer;
    }
};