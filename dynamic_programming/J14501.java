import java.io.*;
import java.util.*;

public class J14501 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        int[][] start = new int[n + 1][2];
        int[] end;
        end = new int[n + 1];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());

            start[i][0] = Integer.parseInt(st.nextToken());
            start[i][1] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < n; i++){
            if(i + start[i][0] <= n){
                end[start[i][0] + i] = Math.max(end[start[i][0] + i], start[i][1] + end[i]);
            }

            end[i + 1] = Math.max(end[i + 1], end[i]);
        }

        bw.write(String.valueOf(end[n]));
        bw.close();
        
    }
}