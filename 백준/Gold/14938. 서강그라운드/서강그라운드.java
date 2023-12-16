import java.io.*;
import java.util.*;

public class Main {
    static int[] item;
    static int n, m, r;
    static ArrayList<Pair>[] conn;
    static int[] maxSumItem;
    static int[] dist;
    static boolean[] check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        conn = new ArrayList[n + 1];
        item = new int[n + 1];
        maxSumItem = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            conn[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            item[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int dest = Integer.parseInt(st.nextToken());
            int length = Integer.parseInt(st.nextToken());

            conn[start].add(new Pair(dest, length));
            conn[dest].add(new Pair(start, length));
        }

        dist = new int[n + 1];
        check = new boolean[n + 1];

        int result = 0;
        for (int i = 1; i <= n; i++) {
            result = Math.max(dijkstra(i), result);  
        }

        System.out.println(result);
    }

    static int dijkstra(int start){
        Arrays.fill(dist, Integer.MAX_VALUE);
        Arrays.fill(check, false);

        PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> p1.length - p2.length);
        pq.add(new Pair(start,0));
        dist[start] = 0;

        while(!pq.isEmpty()){
            Pair curP = pq.poll();
            
            if(!check[curP.dest]){
                check[curP.dest] = true;

                for(Pair pair : conn[curP.dest]){
                    if(!check[pair.dest] && dist[pair.dest] > dist[curP.dest] + pair.length){
                        dist[pair.dest] = dist[curP.dest] + pair.length;
                        pq.add(new Pair(pair.dest, dist[pair.dest]));
                    }
                }
            }
        }

        int result = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] <= m){
                result += item[i];
            }
        }

        return result;
    }
}

class Pair {
    int dest;
    int length;

    Pair(int dest, int length) {
        this.dest = dest;
        this.length = length;
    }
}
