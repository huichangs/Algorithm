import java.util.*;
import java.io.*;

public class Main {
    static int r, c;
    static char[][] arr;
    static int[] xMove = { -1, 1, 0, 0 };
    static int[] yMove = { 0, 0, 1, -1 };
    static boolean[] visited = new boolean[26];
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new char[r][c];

        for (int i = 0; i < r; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < c; j++) {
                arr[i][j] = tmp.charAt(j);
            }
        }

        visited[arr[0][0] - 'A'] = true;
        dfs(0, 0, 1);
        System.out.println(answer);
    }

    static void dfs(int x, int y, int length) {
        answer = Math.max(answer, length);
        
        for (int i = 0; i < 4; i++) {
            int nextX = x + xMove[i];
            int nextY = y + yMove[i];
            if (nextX < 0 || nextX >= r || nextY < 0 || nextY >= c || visited[arr[nextX][nextY] - 'A']) {
                continue;
            }

            visited[arr[nextX][nextY] - 'A'] = true;
            dfs(nextX, nextY, length + 1);
            visited[arr[nextX][nextY] - 'A'] = false;
        }

    }
}
