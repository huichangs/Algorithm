import java.util.*;
import java.io.*;

public class Backtracking15649 {

    public static int[] arr;
    public static boolean[] visited;
    public static StringBuilder sb = new StringBuilder();
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        arr = new int[m];
        visited = new boolean[n + 1];

        back(n, m, 0);

        System.out.println(sb);

    }

    public static void back(int n, int m, int depth){
        if(depth == m){
            for(int j = 0; j < m; j++){
                sb.append(arr[j]).append(' ');
            }
            sb.append('\n');
            return;
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[depth] = i;
                back(n, m, depth + 1);
                visited[i] = false;
            }
        }
    }

}
