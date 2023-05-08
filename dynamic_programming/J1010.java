import java.io.*;
import java.util.*;

public class J1010 {

    static int[][] com = new int[30][30];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        for(int i = 0; i < t; i++){
            st = new StringTokenizer(br.readLine());

            bw.write(String.valueOf(combination(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()))));
            bw.write('\n');
        }

        bw.close();
    }

    public static int combination(int west, int east){
        if(com[east][west] > 0){
            return com[east][west];
        }

        if(west == east || west == 0){
            return com[east][west] = 1;
        }

        return com[east][west] = combination(west - 1, east - 1) + combination(west, east - 1); 
    }
}
