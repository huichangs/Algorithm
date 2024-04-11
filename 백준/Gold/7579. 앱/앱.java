import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int ans = Integer.MAX_VALUE;

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][10001];

        List<Pair> app = new ArrayList<>();

        StringTokenizer st1 = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            app.add(new Pair(Integer.parseInt(st1.nextToken()), Integer.parseInt(st2.nextToken())));
        }

        for(int i = 0; i < n; i++){
            int memory = app.get(i).memory;
            int cost = app.get(i).cost;
            for(int j = 0; j <= 10000; j++){
                if(i == 0){
                    if(j >= cost){
                        dp[i][j] = memory;
                    }
                }else{
                    if(j >= cost){
                        dp[i][j] = Math.max(dp[i - 1][j - cost] + memory, dp[i - 1][j]);
                    }else{
                        dp[i][j] = dp[i - 1][j];
                    }
                }

                if(dp[i][j] >= m){
                    ans = Math.min(ans, j);
                }
            }
        }
        
        System.out.println(ans);
    }

    static class Pair{
        int memory;
        int cost;

        Pair(int memory, int cost){
            this.memory = memory;
            this.cost = cost;
        }
    }
}
