import java.io.*;
import java.util.*;

public class Main {
    static Deque<Pair> queue = new ArrayDeque<>();
    static boolean[] visited = new boolean[100001];
    static int n, k;
    static int answer = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        queue.add(new Pair(n, 0));

        if(n == k){
            System.out.println(0);
            return;
        }

        bfs();
        System.out.println(answer);
    }

    static void bfs(){
        while(!queue.isEmpty()){
            Pair cur = queue.poll();
            visited[cur.location] = true;

            if(cur.location * 2 == k){
                answer = Math.min(answer, cur.time);
            }else{
                if(cur.location * 2 <= 100000){
                    if(!visited[cur.location * 2]){
                        queue.add(new Pair(cur.location * 2, cur.time));
                    }
                }
            }

            if(cur.location + 1 == k){
                answer = Math.min(answer,cur.time + 1);
            }else{
                if (cur.location + 1 <= 100000) {
                    if(!visited[cur.location + 1]){
                        queue.add(new Pair(cur.location + 1, cur.time + 1));
                    }
                }
            }

            if(cur.location - 1 == k){
                answer = Math.min(answer,cur.time + 1);
            }else{
                if(cur.location - 1 >= 0){
                    if(!visited[cur.location - 1]){
                        queue.add(new Pair(cur.location - 1, cur.time + 1));
                    }
                }
            }
        }
    }

    static class Pair{
        int location;
        int time;

        Pair(int location, int time){
            this.location = location;
            this.time = time;
        }
    }
}
