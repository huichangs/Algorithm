import java.util.*;
import java.io.*;

class Solution {
    int m, n, wordSize;
    boolean answer = false;

    public boolean exist(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        wordSize = word.length();
        System.out.println(m);
        System.out.println(n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word.charAt(0)){
                    boolean[][] visited = new boolean[6][6];
                    dfs(j, i, board, 1, word, visited);
                    if(answer == true){
                        return answer;
                    }
                }
            }
        }
        

        
        return answer;
    }

    void dfs(int x, int y, char[][] board, int wordNum, String word, boolean[][] visited){
        if(wordNum == wordSize){
            answer = true;
            return;
        }

        visited[x][y] = true;
        int[] moveX = {-1, 0, 1, 0};
        int[] moveY = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nextX = x + moveX[i];
            int nextY = y + moveY[i];

            if(0 <= nextX && 0 <= nextY && nextX < n && nextY < m && !visited[nextX][nextY]){
                if(board[nextY][nextX] == word.charAt(wordNum)){
                    dfs(nextX, nextY, board, wordNum + 1, word, visited);
                    visited[nextX][nextY] = false;
                }
            }
        }


    }

    
}