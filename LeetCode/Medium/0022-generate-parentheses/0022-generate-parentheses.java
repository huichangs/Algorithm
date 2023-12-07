import java.util.*;
import java.io.*;

class Solution {
    static ArrayList<String> result;
    static int size;
    public ArrayList<String> generateParenthesis(int n) {
        size = n;
        StringBuilder sb = new StringBuilder();
        result = new ArrayList<>();
        backTrack(0, 0, sb);

        return result;
    }

    void backTrack(int n, int openCnt, StringBuilder parentheses){
        if(n == size){
            if (openCnt == 0) {
                result.add(parentheses.toString());
                return;
            }
        }
        
        if(n < size){
            backTrack(n + 1, openCnt + 1, parentheses.append("("));
            parentheses.deleteCharAt(parentheses.length() - 1);
        }
        
        if(openCnt > 0){
            backTrack(n, openCnt - 1, parentheses.append(")"));
            parentheses.deleteCharAt(parentheses.length() - 1);
        }
    }
}