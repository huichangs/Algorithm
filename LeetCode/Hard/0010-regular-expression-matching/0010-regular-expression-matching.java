class Solution {
    Result[][] dpTable;
    public boolean isMatch(String s, String p) {
        dpTable = new Result[s.length() + 1][p.length() + 1];
        return dp(0, 0, s, p);
    }

    public boolean dp(int i, int j, String s, String p){
        if(dpTable[i][j] != null){
            return dpTable[i][j] == Result.TRUE;
        }

        boolean answer;

        if(j == p.length()){
            answer = (i == s.length());
        }else{
            boolean first_match = (i < s.length() && (p.charAt(j) == s.charAt(i) || p.charAt(j) == '.'));

            if(j + 1 < p.length() && p.charAt(j + 1) == '*'){
                answer = dp(i, j + 2, s, p) || (first_match && dp(i + 1, j, s, p));
            }else{
                answer = first_match &&  dp(i + 1, j + 1, s, p);
            }
        }

        dpTable[i][j] = answer ? Result.TRUE : Result.FALSE;
        return answer;
    }
}

enum Result{
    TRUE, FALSE
}