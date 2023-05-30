import java.util.*;
import java.io.*;

public class Bruteforce14889 {
    static int[][] s;
    static int n;
    static ArrayList<Integer> a_diff = new ArrayList<>();
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        s = new int[n][n];
        boolean[] t;
        t = new boolean[n];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                s[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        team(0, 0, t);
        
        bw.write(String.valueOf(Collections.min(a_diff)));
        bw.close();
    }

    public static void team(int now, int depth, boolean[] t){
        if(depth == n / 2){
            a_diff.add(team_diff(t));
            return;
        }

        for(int i = now; i < n; i++){
            t[i] = true;
            team(i + 1, depth + 1, t);
            t[i] = false;
        }

    }

    public static int team_diff(boolean[] t){
        int team_a = 0;
        int team_b = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(t[i] == true && t[j] == true){
                    team_a += s[i][j];
                    //System.out.println("team a : " + i  + "," + j + " : " + team_a);
                }

                if(t[i] == false && t[j] == false){
                    team_b += s[i][j];
                    //System.out.println("team b : " + i  + "," + j + " : " + team_b);
                }
            }
        }

        //System.out.println(Math.abs(team_a - team_b));
        return Math.abs(team_a - team_b);
    }
}
