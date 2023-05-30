import java.util.*;
import java.io.*;

public class Backtracking15650 {
    public static int[] arr;
    public static StringBuilder sb = new StringBuilder();
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        arr = new int[m];

        back(1, n, m, 0);

        System.out.println(sb);

    }

    public static void back(int now, int n, int m, int depth){
        if(depth == m){
            for(int j : arr){
                sb.append(j).append(' ');
            }
            sb.append('\n');
            return;
        }

        for(int i = now; i <= n; i++){
            arr[depth] = i;
            back(i + 1, n, m, depth + 1);
        }
    }
}
