class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> hash = new HashMap<>();
        int longestNum = 0;
        int left = 0;

        for(int i = 0; i < s.length(); i++){
            char tmp = s.charAt(i);
            if(hash.containsKey(tmp)){
                longestNum = Math.max(longestNum, i - left);

                for(int j = left; j < hash.get(tmp); j++){
                    hash.remove(s.charAt(j));
                }

                left = hash.get(tmp) + 1;
            }

            hash.put(tmp, i);
        }
        longestNum = Math.max(longestNum, s.length() - left);
        
        return longestNum;
    }
}