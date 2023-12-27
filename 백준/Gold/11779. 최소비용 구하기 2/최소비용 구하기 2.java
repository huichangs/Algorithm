import java.util.*;
import java.io.*;

public class Main {
    static ArrayList<Pair>[] conn;
    static int[] dist;
    static int n, m, start, end;
    static int[] path;
    static Deque<Integer> stack = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        conn = new ArrayList[n + 1];
        dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        path = new int[n + 1];

        for (int i = 0; i <= n; i++)
            conn[i] = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            conn[s].add(new Pair(e, weight));
        }

        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        dijkstra();
        findPath();

        System.out.println(dist[end]);
        int size = 1 + stack.size();
        System.out.println(size);
        System.out.print(start + " ");
        for (int i = 0; i < size - 1; i++) {
            System.out.print(stack.pop() + " ");
        }

    }

    static void dijkstra() {

        PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> p1.weight - p2.weight);
        boolean[] visited = new boolean[n + 1];
        pq.add(new Pair(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Pair p = pq.poll();

            if(visited[p.dest]) continue;
            visited[p.dest] = true;

            for (Pair nextP : conn[p.dest]) {
                if (dist[nextP.dest] > dist[p.dest] + nextP.weight) {
                    dist[nextP.dest] = dist[p.dest] + nextP.weight;
                    pq.add(new Pair(nextP.dest, dist[nextP.dest]));

                    path[nextP.dest] = p.dest;
                }
            }
        }

    }

    static void findPath() {
        int parent = end;

        while (parent != start) {
            stack.push(parent);
            parent = path[parent];
        }
    }

    static class Pair {
        int dest;
        int weight;

        Pair(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }
}
