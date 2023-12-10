import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static StringBuilder sb = new StringBuilder();
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};
    static char[][] map = new char[55][55];
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new char[n][n];
        for(int i=0; i<n; i++) {
            String str = br.readLine();
            for(int j=0; j<n; j++) {
                map[i][j] = str.charAt(j);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx<0 || nx>=n || ny<0 || ny>=n) {
                        continue;
                    }
                    swap(i, j, nx, ny);
                    solve();
                    swap(i, j, nx, ny);
                }
            }
        }
        System.out.println(ans);
    }
    static void swap(int a, int b, int c, int d) {
        char t = map[a][b];
        map[a][b] = map[c][d];
        map[c][d] = t;
    }
    static void solve() {
        for(int i=0; i<n; i++) {
            int k = 1;
            for(int j=1; j<n; j++) {
                if(map[i][j]==map[i][j-1]) {
                    k++;
                } else {
                    ans = Math.max(ans, k);
                    k = 1;
                }
            }
            ans = Math.max(ans, k);
        }
        for(int i=0; i<n; i++) {
            int k = 1;
            for(int j=1; j<n; j++) {
                if(map[j][i]==map[j-1][i]) {
                    k++;
                } else {
                    ans = Math.max(ans, k);
                    k = 1;
                }
            }
            ans = Math.max(ans, k);
        }
    }
}